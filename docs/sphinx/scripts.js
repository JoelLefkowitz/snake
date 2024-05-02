Array.from(document.querySelectorAll("img"))
  .filter((img) => img.hasAttribute("height"))
  .forEach((img) => {
    img.style.height = img.getAttribute("height").concat("px");
  });

Array.from(document.querySelectorAll("span.std.std-ref")).forEach((span) => {
  span.textContent = span.textContent
    .replaceAll("< ", "<")
    .replaceAll(" >", ">");
});
