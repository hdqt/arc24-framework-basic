#!/usr/bin/bash

THIS_DIR="$(realpath "$(dirname "${BASH_SOURCE[0]}")")"

PROJECT_ROOT_DIR="$(git rev-parse --show-toplevel)"

#
# ./libsrc/api/CMakeLists.txt
#
API_CMAKELISTS_TEMPLATE_PATH="${THIS_DIR}/libsrc_api_CMakeLists.txt.template"

API_DIR="${PROJECT_ROOT_DIR}/libsrc/api"
API_CMAKELISTS_FILE_PATH="${API_DIR}/CMakeLists.txt"

LIB_PUBLIC_SOURCES=$(find "$API_DIR" -name "*.hpp" -printf "    %P\n")

awk -v LIB_PUBLIC_SOURCES="$LIB_PUBLIC_SOURCES" '{
    if ($0 == "__LIB_PUBLIC_SOURCES__") {
        print LIB_PUBLIC_SOURCES
    }
    else {
        print
    }
}' "$API_CMAKELISTS_TEMPLATE_PATH" > $API_CMAKELISTS_FILE_PATH


#
# ./libsrc/src/CMakeLists.txt
#
SRC_CMAKELISTS_TEMPLATE_PATH="${THIS_DIR}/libsrc_src_CMakeLists.txt.template"

SRC_DIR="${PROJECT_ROOT_DIR}/libsrc/src"
SRC_CMAKELISTS_FILE_PATH="${SRC_DIR}/CMakeLists.txt"

LIB_PRIVATE_SOURCES=$(find "$SRC_DIR" -name "*.[hc]pp" -printf "    %P\n")

awk -v LIB_PRIVATE_SOURCES="$LIB_PRIVATE_SOURCES" '{
    if ($0 == "__LIB_PRIVATE_SOURCES__") {
        print LIB_PRIVATE_SOURCES
    }
    else {
        print
    }
}' "$SRC_CMAKELISTS_TEMPLATE_PATH" > $SRC_CMAKELISTS_FILE_PATH
