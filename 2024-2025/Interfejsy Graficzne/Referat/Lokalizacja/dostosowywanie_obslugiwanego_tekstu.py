import wx

class UnicodeApp(wx.Frame):
    def __init__(self):
        super().__init__(None, title="Unicode i RTL Obsługa", size=(400, 300))
        
        self.panel = wx.Panel(self)

        self.sizer = wx.BoxSizer(wx.VERTICAL)
        
        # Japoński tekst zapisany w Unicode
        # もうすぐクリスマス - Wkrótce Święta Bożego Narodzenia
        asian_unicode_text = wx.StaticText(self.panel, label=u"\u3082\u3046\u3059\u3050\u30af\u30ea\u30b9\u30de\u30b9 (Wkrótce Święta Bożego Narodzenia po Japońsku)")  
        asian_unicode_text.SetFont(wx.Font(7, wx.FONTFAMILY_DEFAULT, wx.FONTSTYLE_NORMAL, wx.FONTWEIGHT_BOLD))
        
        # Tekst Arabski RTL
        # النص العربي هنا - Wkrótce Święta Bożego Narodzenia
        arabic_rtl_text = wx.StaticText(self.panel, label="(Wkrótce Święta Bożego Narodzenia po Arabsku) النص العربي هنا")
        arabic_rtl_text.SetFont(wx.Font(7, wx.FONTFAMILY_DEFAULT, wx.FONTSTYLE_NORMAL, wx.FONTWEIGHT_BOLD))

        # Ustawienie wyrównania tekstu na prawą stronę, obsługa RTL 
        arabic_rtl_text.SetWindowStyle(wx.ALIGN_RIGHT)

        self.sizer.Add(asian_unicode_text, 0, wx.EXPAND | wx.ALL, 10)
        self.sizer.Add(arabic_rtl_text, 0, wx.EXPAND | wx.ALL, 10)
        
        self.panel.SetSizer(self.sizer)

if __name__ == "__main__":
    app = wx.App()
    frame = UnicodeApp()
    frame.Show()
    app.MainLoop()
