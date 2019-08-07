[alias]

  auto-dry-run = "!f() { \
    : auto-complete-disabled ; \
    for c in awk cat cut echo git grep sed tr xargs; do if ! command -v ${c} 1> /dev/null; then echo "${c} was NOT found, exiting..."; echo exit 1; fi; done; \
    repository_name=$(git remote get-url origin|tr ./:@ _ 2> /dev/null); \
    [ -n "${repository_name}" ] || { echo "repository_name was NOT found, exiting..."; exit 1; }; \
    echo "${*:-CLI}" > /tmp/"${repository_name}".msg; \
    git commit --all --porcelain|grep -v '??' >> /tmp/"${repository_name}".msg; \
    if [ -s /tmp/"${repository_name}".msg ]; then \
      cat /tmp/"${repository_name}".msg; \
    fi; \
    }; f"
