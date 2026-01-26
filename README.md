# Trading System Simulator
This project simulates the full lifecycle of an automated trading system:
```
Market Data
   ↓  (lock-free SPSC queue)
Strategy Engine
   ↓  (orders)
Execution Simulator
```
---
## Core Features
### 1. Market Data Engine
* NASDAQ L2-style order book simulation using aggregated price levels
* Historical tick replay from CSV with time scaling
* Single-producer event publishing

### 2. Strategy Engine (*in progress*)
* Polymorphic C++ strategy interface
* Python strategies integrated via **pybind11**
* Python objects initialized once and reused (no per-tick allocation)
* GIL-aware invocation for minimal overhead

Implemented strategies:
* **Mean Reversion**
  * Rolling mean & standard deviation
  * Z-score entry/exit logic
* **Momentum**
  * EMA crossover trend-following
* **Pairs Trading**
  * Linear regression hedge ratio
  * Spread z-score signals
---
## Build & Run
### Requirements
* Linux
* C++20 compiler (GCC / Clang)
* CMake ≥ 3.20
* Python 3.x
* NumPy
* pybind11
* Boost (for lock-free SPSC queue)

### Build

```bash
mkdir build
cd build
cmake ..
```

### Run

```bash
./trading-system
```
---
