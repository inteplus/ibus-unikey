### Phiên bản nhái từ ibus-unikey của Lê Quốc Tuấn. Tuy nhiên có thêm bộ gõ Envi để gõ trộn lẫn tiếng Anh và tiếng Việt.

This variant contains Envi, an input method modified from Telex to support typing both English and Vietnamese more easily than Telex. You type:

Single key stroke for a tone with lowest probability of hitting an English bigram

  * Q (0.001030) for sắc
  * Z (0.001142) for huyền
  * X (0.001933) for ngã
  * J (0.002077) for nặng
  * K (0.008084) for hỏi

Single suffix key to form a Vietnamese letter with very low probability of hitting an English bigram

  * aa (0.000398) for â
  * aw (0.000906) for ă
  * ee (0.004278) for ê
  * oo (0.002352) for ô
  * op (0.002419) for ơ
  * uu (0.000015) for ư
  * dd (0.000925) for đ

These letters were chosen to minimise the probability of hitting an English bigram (using the English and Vietnamese Wikipedia corpora) and to preserve/enhance the fast typing pace of Telex.


IBus-Unikey IME
===============

[![Build Status](https://travis-ci.org/vn-input/ibus-unikey.svg?branch=master)](https://travis-ci.org/vn-input/ibus-unikey)

ibus-unikey is an [IBus](https://github.com/ibus/ibus) IME.
It use Unikey-engine for progress key event.
(a modified version of it)

### For install, please visit [wiki](https://github.com/vn-input/ibus-unikey/wiki) page

