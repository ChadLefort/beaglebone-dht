{
  "targets": [
    {
      "target_name": "beaglebone-dht",
      "sources": [ "src/bbb_dht.cc", "src/common_dht_read.c", "src/bbb_dht_read.c", "src/bbb_mmio.c" ],
      "include_dirs" : ["<!(node -e \"require('nan')\")"]
    }
  ]
}