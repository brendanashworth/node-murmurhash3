{
  "targets": [
    {
      "target_name": "murmurhash",
      "sources": [
        "src/binding.cc",
        "deps/murmurhash.c/murmurhash.c"
      ],
      "include_dirs": [
        "deps",
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}