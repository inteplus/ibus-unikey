
[IBus-Unikey - a Vietnamese Input Method Editor designed for GNU/Linux](https://github.com/ibus-unikey/ibus-unikey)
===============

Copyright 2009-2018, The IBus-Unikey Authors.

This variant contains Envi, an input method modified from Telex to support typing both English and Vietnamese more easily than Telex. You type:

Single key stroke for a tone with lowest probability of hitting an English bigram

  * Q (0.001030) for sắc
  * Z (0.001142) for huyền
  * X (0.001933) for nặng
  * J (0.002077) for hỏi
  * K (0.008084) for ngã

Single suffix key to form a Vietnamese letter with very low probability of hitting an English bigram

  * aa (0.000398) for â
  * ae (0.000188) for ă
  * eu (0.000849) for ê
  * oo (0.002352) for ô
  * op (0.002419) for ơ
  * uu (0.000015) for ư
  * dd (0.000925) for đ

These letters were chosen to minimise the probability of hitting an English bigram (using the English and Vietnamese Wikipedia corpora) and to preserve/enhance the fast typing pace of Telex.

Build Status
------------

Source Pull Instructions
------------------------

This repo contains a submodule, libunikey. Beside the usual git clone/pull commands, you now can use the '--recursive' option to pull the submodule. You may also want to do 'git submodule init' followed by 'git submodule update'.


Build Instructions
------------------

* [How to build in GNU/Linux](docs/build_unikey_in_linux.md): Debian/Ubuntu build.

License
-------

All IBus-Unikey code written by IBus-Unikey Team is released under
[The GNU General Public License](https://opensource.org/licenses/gpl-3.0).
For third party code under [src/third_party](src/third_party) directory,
see each sub directory to find the copyright notice.