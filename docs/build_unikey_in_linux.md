How to build Ibus-Unikey in GNU/Linux
=====================================

# System Requirements
Currently, only Ubuntu 16.04 is tested to build IBus.

# Dependencies

IBus-Unikey requires gcc 4.9+ with C++14 support.

# Ubuntu 16.04 LTS

The following packages are required:

```
sudo apt-get install \
    git \
    g++ \
    cmake \
    make \
    pkg-config \
    libspdlog-dev \
    libibus-1.0-dev \
    libgtk2.0-dev

```

In the ibus-unikey directory, run:

```
  cd build
  cmake -DCMAKE_INSTALL_PREFIX:PATH=/usr -DCMAKE_BUILD_TYPE=Release ..
  make -j $(nproc)
  sudo make install
```
