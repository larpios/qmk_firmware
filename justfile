# https://just.systems
KEYBOARD := "voyager"
KEYMAP := "larpi"

default:
    @just --list

build:
    @qmk compile -kb {{KEYBOARD}} -km {{KEYMAP}}

flash:
    @qmk flash -kb {{KEYBOARD}} -km {{KEYMAP}}

setup:
    @qmk setup
