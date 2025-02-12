import { logger } from "file-loggers";
import { drop } from "ramda";
import fs from "fs";
import path from "path";

const rewrite = (file: string, update: (text: string) => string): void =>
  fs.writeFileSync(file, update(fs.readFileSync(file, "utf8")));

export default {
  name: "guards",
  description: "Check header guards are consistent",
  action: () =>
    logger(
      "src/**/*.[ht]pp",
      async (file) =>
        rewrite(file, (text) => {
          const lines = text.split("\n");
          const guard = drop("#ifndef".length + 1, lines[0]);

          const derived = ["funky"]
            .concat(path.relative("src", file).split(path.sep))
            .join("_")
            .replace(/\./g, "_")
            .toUpperCase();

          const [ifndef, define] = lines;

          if (
            lines.length < 2 ||
            !ifndef.startsWith("#ifndef") ||
            !define.startsWith("#define")
          ) {
            throw new Error("The first lines should be a header guard");
          }

          return guard === derived
            ? text
            : [`#ifndef ${derived}`, `#define ${derived}`]
                .concat(lines.slice(2))
                .join("\n");
        }),
      {
        count: true,
        trail: true,
        timer: true,
      },
    ),
};
