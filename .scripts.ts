import { concurrent } from "nps-utils";

export default {
  scripts: {
    lint: concurrent({
      cppcheck: "cppcheck --enable=style,performance,portability src",
      spellcheck: "cspell . --dot --unique --no-progress --no-summary",
      secrets: "trufflehog3",
    }),
    format: concurrent({
      prettier: "prettier . --write",
      clang: "clang-format -i -style=file --verbose **/*.*pp",
    }),
  },
};
