import os


def extract(path, start, end):
    with open(path) as stream:
        lines = stream.read().split("\n")
        lower = lines.index(start) + 1 if start in lines else len(lines)
        upper = lines.index(end) if end in lines else 0
        return "\n".join(lines[lower:upper])


start = "namespace paths {"
end = "} // namespace paths"

src = os.path.normpath(os.path.join(__file__, "..", "..", "src"))

headers = map(
    lambda x: os.path.join(src, x),
    sorted(
        filter(lambda x: x.endswith(".hpp"), os.listdir(src)),
        key=lambda x: 0 if x == "runtime.hpp" else 1,
    ),
)

namespace = "\n\n".join(
    filter(lambda x: x != "", map(lambda x: extract(x, start, end), headers))
)

print("\n".join([start, namespace, end]))
