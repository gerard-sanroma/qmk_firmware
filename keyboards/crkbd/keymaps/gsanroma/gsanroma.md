### conf
- copy [`50-qmk.rules`](https://github.com/qmk/qmk_firmware/blob/master/util/udev/50-qmk.rules) to `/etc/udev/rules.d/`

### Flash

**[from gh/footstan](https://github.com/foostan/crkbd/blob/v3-final/doc/firmware_en.md)**
`make crkbd:via` (compile)
`make crkbd:via:avrdude` (flash)

qmk compile -kb crkbd/rev1 -km gsanroma
qmk flash -kb crkbd/rev1 -km gsanroma -bl avrdude

# compile crkbd `rev4_1` (oscar)

qmk `compile -kb crkbd/rev4_1/standard -km default`
