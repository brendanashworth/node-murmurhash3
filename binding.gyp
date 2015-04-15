{
  "targets": [
    {
      "target_name": "murmurhash",
      "sources": [
        "src/binding.cc",
        "deps/murmurhash.c/murmurhash.c"
      ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}