#!/bin/bash

echo "" > src/lib.rs

for file in src/*.rs; do
  filename=$(basename "$file")
  if [ "$filename" = "lib.rs" ]; then
    continue
  fi

  module_name="${filename#*.}"
  module_name="${module_name//[-]/_}"
  module_name="${module_name%.rs}"

  echo "#[path = \"$filename\"]" >> src/lib.rs
  echo "pub mod $module_name;" >> src/lib.rs
  echo "" >> src/lib.rs
done
