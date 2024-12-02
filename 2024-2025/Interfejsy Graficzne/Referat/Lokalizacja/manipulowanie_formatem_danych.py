import wx
import locale
from datetime import datetime

class LocaleApp(wx.Frame):
    def __init__(self):
        super().__init__(None, title="Manipulacja Formatem Danych", size=(400, 300))
        
        self.panel = wx.Panel(self)

        self.sizer = wx.BoxSizer(wx.VERTICAL)
        
        # Dropdown z wyborem języka
        self.locale_choice = wx.Choice(self.panel, choices=["pl_PL", "en_US"])
        
        # Wybór domyślny Języka Polskiego
        self.locale_choice.SetSelection(0)
        self.locale_choice.Bind(wx.EVT_CHOICE, self.update_format)
        
        # Tekst do wyświetlenia wyniku
        self.output_text = wx.StaticText(self.panel, label="Wynik")

        self.sizer.Add(self.locale_choice, 0, wx.EXPAND | wx.ALL, 10)
        self.sizer.Add(self.output_text, 1, wx.EXPAND | wx.ALL, 10)
        
        self.panel.SetSizer(self.sizer)

        # Inicjacja z domyślnym formatem dla Języka Polskiego
        self.update_format(None)
        
    def update_format(self, event):
        selected_locale = self.locale_choice.GetStringSelection()
        try:
            locale.setlocale(locale.LC_ALL, selected_locale)
        except locale.Error:
            self.output_text.SetLabel("Nie można ustawić lokalizacji.")
            return
        
        # Pobranie sformatowanych danych
        current_time = datetime.now().strftime("%c")
        formatted_number = locale.format_string("%.2f", 12345.678, grouping=True)
        formatted_currency = locale.currency(12345.678, grouping=True)
        
        # Ustawienie tekstu wyjściowego
        self.output_text.SetLabel(f"Liczba: {formatted_number}\nData i godzina: {current_time}\nWaluta: {formatted_currency}")

if __name__ == "__main__":
    app = wx.App()
    frame = LocaleApp()
    frame.Show()
    app.MainLoop()
