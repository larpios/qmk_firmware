# https://just.systems
DEFAULT_KEYBOARD := "voyager"
DEFAULT_KEYMAP := "larpi"

default:
    @just --list

build keyboard=DEFAULT_KEYBOARD keymap=DEFAULT_KEYMAP:
    @qmk compile -kb {{keyboard}} -km {{keymap}}

flash keyboard=DEFAULT_KEYBOARD keymap=DEFAULT_KEYMAP:
    @qmk flash -kb {{keyboard}} -km {{keymap}}

import source_archive keyboard=DEFAULT_KEYBOARD keymap=DEFAULT_KEYMAP:
    @mkdir -p tmp
    @ouch d {{source_archive}} -d tmp
    @cp $(fd -t d . tmp/ | tail -n 1)/* keyboards/zsa/{{keyboard}}/keymaps/{{keymap}}/
    @rm -rf tmp/

setup:
    @qmk setup
