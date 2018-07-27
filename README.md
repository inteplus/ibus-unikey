
[IBus-Unikey - a Vietnamese Input Method Editor designed for GNU/Linux](https://github.com/ibus-unikey/ibus-unikey)
===============

Copyright 2009-2018, The IBus-Unikey Authors.

This variant contains Envi, an input method modified from Telex to support typing both English and Vietnamese more easily than Telex. You type:
* aa for â (like Telex)
* aw for ă (like Telex)
* ee for ê (like Telex)
* dd for đ (like Telex)
* oo for ô
* ol for ơ
* uu for ư
* k for acute tone (sắc)
* z for grave tone (huyền)
* q for hook tone (hỏi)
* x for tilde tone (ngã) (like Telex)
* j for dot tone (nặng) (like Telex)

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