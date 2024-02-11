// SPDX-FileCopyrightText: 2002-2023 PCSX2 Dev Team
// SPDX-License-Identifier: LGPL-3.0+

#pragma once

#include "ui_MemorySearchWidget.h"

#include "DebugTools/DebugInterface.h"

#include <QtWidgets/QWidget>
#include <QtCore/QTimer>
#include <QtCore/QMap>

class MemorySearchWidget final : public QWidget
{
    Q_OBJECT

public:
	MemorySearchWidget(QWidget* parent);
    ~MemorySearchWidget() = default;
	void setCpu(DebugInterface* cpu);

    enum class SearchType
	{
		ByteType,
		Int16Type,
		Int32Type,
		Int64Type,
		FloatType,
		DoubleType,
		StringType,
		ArrayType
	};

	// Note: The order of these enum values must reflect the order in thee Search Comparison combobox.
	enum class SearchComparison
	{
		Equals,
		NotEquals,
		GreaterThan,
		GreaterThanOrEqual,
		LessThan,
		LessThanOrEqual,
		Increased,
		IncreasedBy,
		Decreased,
		DecreasedBy,
		Changed,
		NotChanged
	};

	class SearchResult
	{
	private:
		u32 address;
		QVariant value;
		SearchType type;

	public:
		SearchResult() {}
		SearchResult(u32 address, const QVariant& value, SearchType type)
			: address(address), value(value), type(type)
		{
		}
		bool isIntegerValue() const { return !isArrayValue(); }
		bool isArrayValue() const { return type == SearchType::ArrayType || type == SearchType::StringType; }
		u32 getAddress() const { return address; }
		SearchType getType() const { return type; }
		u32 getIntegerValue() const { return isIntegerValue() ? value.toUInt() : 0; }
		QByteArray getArrayValue() const { return isArrayValue() ? value.toByteArray() : QByteArray(); }
	};

public slots:
	void onSearchButtonClicked();
	void onSearchResultsListScroll(u32 value);
	void onSearchTypeChanged(int newIndex);
	void loadSearchResults();
	void contextSearchResultGoToDisassembly();
	void contextRemoveSearchResult();
	void contextCopySearchResultAddress();
	void onListSearchResultsContextMenu(QPoint pos);

signals:
	void addAddressToSavedAddressesList(u32 address);
	void goToAddressInDisassemblyView(u32 address);
	void goToAddressInMemoryView(u32 address);
	void switchToMemoryViewTab();

private:
    std::vector<u32> m_searchResults;
	QMap<u32, SearchResult> m_searchResultsMap;

    Ui::MemorySearchWidget m_ui;

    DebugInterface* m_cpu;
    QTimer m_resultsLoadTimer;

    u32 m_initialResultsLoadLimit = 20000;
	u32 m_numResultsAddedPerLoad = 10000;
};
