# with import <nixpkgs> {};
# mkShell {
#   nativeBuildInputs = with pkgs; [ clang-tools ];
# }

with import <nixpkgs> {};
mkShell {
  nativeBuildInputs = with pkgs; [ clang-tools ];
}
