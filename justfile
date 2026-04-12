# https://just.systems
DEFAULT_KEYBOARD := "voyager"
DEFAULT_KEYMAP := "larpi"

default:
    @just --list

build keyboard=DEFAULT_KEYBOARD keymap=DEFAULT_KEYMAP:
    @qmk compile -kb {{keyboard}} -km {{keymap}}

flash keyboard=DEFAULT_KEYBOARD keymap=DEFAULT_KEYMAP:
    @qmk flash -kb {{keyboard}} -km {{keymap}}

setup:
    @qmk setup
