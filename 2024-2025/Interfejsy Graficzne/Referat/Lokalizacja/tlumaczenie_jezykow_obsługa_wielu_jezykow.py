import wx
import gettext
import os

class TranslatorApp(wx.Frame):
    def __init__(self):
        super().__init__(None, title="Tłumacz", size=(400, 300))

        self.panel = wx.Panel(self)

        self.sizer = wx.BoxSizer(wx.VERTICAL)

        self.translate_button = wx.Button(self.panel, label="Dokonaj Tłumaczenia")
        self.translate_button.Bind(wx.EVT_BUTTON, self.on_translate)

        self.text_label = wx.StaticText(self.panel, label="Lorem Ipsum jest po prostu tekstem zastępczym w przemyśle poligraficznym i składzie tekstu. Lorem Ipsum jest standardowym tekstem zastępczym w przemyśle od lat 1500, kiedy nieznany drukarz wziął galerię czcionek i pomieszał je, aby stworzyć książkę z próbkami czcionek.")

        self.sizer.Add(self.translate_button, 0, wx.ALL | wx.CENTER, 10)
        self.sizer.Add(self.text_label, 1, wx.EXPAND | wx.ALL, 10)

        self.panel.SetSizer(self.sizer)

        self.current_language = "pl"
        self.setup_translation(self.current_language)

    def setup_translation(self, lang):
        """Konfiguruje tłumaczenie dla danego języka."""
        locales_path = os.path.join(os.path.dirname(__file__), "locales")
        translation = gettext.translation("messages", locales_path, languages=[lang], fallback=True)
        translation.install()
        self._ = translation.gettext

        # Aktualizacja interfejsu
        self.SetTitle(self._("Tłumacz"))
        self.translate_button.SetLabel(self._("Dokonaj Tłumaczenia"))
        self.text_label.SetLabel(self._("Lorem Ipsum jest po prostu tekstem zastępczym w przemyśle poligraficznym i składzie tekstu. Lorem Ipsum jest standardowym tekstem zastępczym w przemyśle od lat 1500, kiedy nieznany drukarz wziął galerię czcionek i pomieszał je, aby stworzyć książkę z próbkami czcionek."))

    def on_translate(self, event):
        """Przełącza język i tłumaczy tekst."""
        self.current_language = "en" if self.current_language == "pl" else "pl"
        self.setup_translation(self.current_language)

        # Dopasowanie sizerów do nowego rozmiaru tekstu
        self.sizer.Layout()

if __name__ == "__main__":
    app = wx.App()
    frame = TranslatorApp()
    frame.Show()
    app.MainLoop()