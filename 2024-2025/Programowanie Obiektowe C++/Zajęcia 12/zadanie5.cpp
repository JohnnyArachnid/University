#include <iostream>
#include <vector>
#include <memory>

class Visitor;

class DocumentElement {
public:
    virtual ~DocumentElement() = default;
    virtual void accept(Visitor& visitor) = 0;
};

class TextElement : public DocumentElement {
public:
    void accept(Visitor& visitor) override;
    void displayText() const { std::cout << "Tekst: Hello World\n"; }
};

class ImageElement : public DocumentElement {
public:
    void accept(Visitor& visitor) override;
    void displayImage() const { std::cout << "Obrazek: [Obrazek.jpeg]\n"; }
};

class Visitor {
public:
    virtual void visit(TextElement& text) = 0;
    virtual void visit(ImageElement& image) = 0;
};

void TextElement::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void ImageElement::accept(Visitor& visitor) {
    visitor.visit(*this);
}

class RenderVisitor : public Visitor {
public:
    void visit(TextElement& text) override {
        std::cout << "[Renderowanie tekstu]\n";
        text.displayText();
    }

    void visit(ImageElement& image) override {
        std::cout << "[Renderowanie obrazka]\n";
        image.displayImage();
    }
};

class ExportPDFVisitor : public Visitor {
public:
    void visit(TextElement& text) override {
        std::cout << "Eksportuje tekst do PDF...\n";
    }

    void visit(ImageElement& image) override {
        std::cout << "Eksportuje obrazek do PDF...\n";
    }
};

int main() {
    std::vector<std::unique_ptr<DocumentElement>> document;

    document.emplace_back(std::make_unique<TextElement>());
    document.emplace_back(std::make_unique<ImageElement>());

    RenderVisitor renderer;
    ExportPDFVisitor exporter;

    std::cout << "\n--- Renderowanie dokumentu ---\n";
    for (auto& elem : document) {
        elem->accept(renderer);
    }

    std::cout << "\n--- Eksportowanie dokumentu ---\n";
    for (auto& elem : document) {
        elem->accept(exporter);
    }

    return 0;
}