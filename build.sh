#!/bin/bash

set -x


if [ $# -eq 2 ]; then

    odin build src -out:hanoi.bin -o:speed -reloc-mode:static && echo "OK"

elif [ $# -eq 1 ]; then

    odin build src -debug -out:hanoi.bin && echo "OK"
else

    odin build src -out:hanoi.bin && echo "OK"

fi
