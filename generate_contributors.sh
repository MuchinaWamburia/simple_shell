#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <path_to_git_repo>"
    exit 1
fi

repo_path="$1"
authors_file="$repo_path/AUTHORS"

generate_contributors() {
    git -C "$repo_path" shortlog -s -n
}

generate_authors_file() {
    generate_contributors | awk '{print $2 " " $3}' > "$authors_file"
}

echo "Updating CONTRIBUTORS file..."
generate_authors_file
echo "Contributors list has been updated and saved to $authors_file"
