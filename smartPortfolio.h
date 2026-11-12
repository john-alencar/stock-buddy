#pragma once
#ifndef STOCKBUDDY_SMARTPORTFOLIO_H
#define STOCKBUDDY_SMARTPORTFOLIO_H

// Refactor of `Portfolio` module to include asset ownership using smart pointers.
// Deep-copyable; move constructor and move assignment are explicitly defaulted since copy assignment overload suppresses them.

#include <cstddef>
#include <vector>
#include <memory>
#include <iosfwd>
#include "Asset.h"

namespace stockbuddy {
	class SmartPortfolio {
		std::vector<std::unique_ptr<Asset>> m_asset;
	public:
		SmartPortfolio() = default;
		SmartPortfolio(const SmartPortfolio& other);
		SmartPortfolio(SmartPortfolio&& other) noexcept = default;
		SmartPortfolio& operator=(const SmartPortfolio& other);
		SmartPortfolio& operator=(SmartPortfolio&& other) noexcept = default;
		/// Stores a deep copy of the asset, created via cloneUnique(*asset), at the end; ignores null.
		SmartPortfolio& add(const Asset* asset);
		/// Takes ownership of an asset the caller passes with std::move; ignores null.
		SmartPortfolio& add(std::unique_ptr<Asset> asset);
		std::size_t size() const;
		/// Returns a read-only pointer to the asset at index or nullptr if out of bounds.
		const Asset* operator[](std::size_t index) const;
		double totalValue() const;
		void display(std::ostream& os) const;
		/// Exchanges stored assets with another portfolio in without throwing; used by copy-and-swap assignment.
		void swap(SmartPortfolio& other) noexcept;
	};
	/// Returns a dynamically created copy of the asset wrapped in a unique_ptr.
	std::unique_ptr<Asset> cloneUnique(const Asset& asset);
}


#endif
