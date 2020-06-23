### Phiên bản nhái từ ibus-unikey của Lê Quốc Tuấn. Tuy nhiên có thêm bộ gõ Envi để gõ trộn lẫn tiếng Anh và tiếng Việt.

This variant contains Envi, an input method modified from Telex to support typing both English and Vietnamese concurrently, and more easily than Telex. You type:

Single key stroke for a tone with the lowest probability of hitting an English bigram

  * X (0.0019) for sắc
  * Q (0.0025) for nặng
  * Z (0.0095) for huyền
  * J (0.0035) for hỏi
  * B (0.0110) for ngã

Single suffix key to form a Vietnamese letter with a very low probability of hitting an English bigram

  * aa (0.000398) for â
  * aw (0.000906) for ă
  * ee (0.004278) for ê
  * oo (0.002352) for ô
  * ol (0.003174) for ơ
  * uu (0.000015) for ư
  * dd (0.000925) for đ

These letters were chosen to minimise the probability of hitting an English bigram (using the English and Vietnamese Wikipedia corpora as of 2018) and to preserve/enhance the fast typing pace of Telex.


IBus-Unikey IME
===============

[![Build Status](https://travis-ci.org/vn-input/ibus-unikey.svg?branch=master)](https://travis-ci.org/vn-input/ibus-unikey)

ibus-unikey is an [IBus](https://github.com/ibus/ibus) IME.
It uses Unikey-engine for progress key event.
(a modified version of it)

### The repo uses https://github.com/inteplus/libunikey.git as a submodule. Make sure you use the --recursive option or something equivalent when cloning the repo.

### For install, please visit [wiki](https://github.com/vn-input/ibus-unikey/wiki) page

