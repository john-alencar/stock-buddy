# StockBuddy

A C++20 console app that tracks a stock portfolio and watchlist, and flags
holdings that look cheap on a P/E + PEG basis.

## Features

- Portfolio of stocks, dividend stocks and ETFs, each valued its own way
- Cheap-zone detection: trailing P/E against a per-stock ceiling
- Growth-bargain detection: PEG <= 1.0 outside the cheap zone
- Watchlist and broker linking for holdings you don't own (yet)
- Filter and sort holdings with custom conditions

## Build and run

```bash
g++ -Wall -std=c++17 -g -o stockbuddy src/*.cpp
./stockbuddy
```

## Implementation

- Owning containers with full move semantics
- Polymorphic assets (`Stock`, `DividendStock`, `Etf`) behind an abstract base
- A header-only dynamic-array class template
- Ownership: the portfolio owns its holdings, the watchlist only
  references them, the broker is only associated with a portfolio
