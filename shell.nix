with import <nixpkgs> {};
mkShell {
  nativeBuildInputs = with pkgs; [ clang-tools gdb ];
  hardeningDisable = [ "all" ];
}
