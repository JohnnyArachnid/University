import wx

app = wx.App()

frame = wx.Frame(None, title="Sizer FlexGridSizer Przykład", size=(400, 300))

panel = wx.Panel(frame)

# Tworzymy sizer typu FlexGridSizer z 2 wierszami i 3 kolumnami oraz odstępami o wartości 5 pikseli w pionie i poziomie
sizer = wx.FlexGridSizer(2, 3, 5, 5)

button1 = wx.Button(panel, label="Przycisk 1")
button2 = wx.Button(panel, label="Przycisk 2")
button3 = wx.Button(panel, label="Przycisk 3")

buttons = [
    (wx.Button(panel, label="Przycisk 4"), 0, wx.EXPAND),
    (wx.Button(panel, label="Przycisk 5"), 0, wx.EXPAND),
    (wx.Button(panel, label="Przycisk 6"), 0, wx.EXPAND),
]

sizer.Add(button1, 0, wx.ALIGN_LEFT | wx.ALL, 5)
sizer.Add(button2, 1, wx.ALIGN_CENTER | wx.ALL, 5)
sizer.Add(button3, 0, wx.ALIGN_RIGHT | wx.ALL, 5)

sizer.AddMany(buttons)  

# Dodajemy elastyczność do kolumn i wierszy
# Kolumna 1 ma większy priorytet rozciągania niż pozostałe
# Pierwszy argument AddGrowableCol to nr kolumny, a drugi to jej priorytet
sizer.AddGrowableCol(0, 2)  
# Wiersz 2 ma większy priorytet rozciągania niż pozostałe
# Pierwszy argument AddGrowableRow to nr wiersza, a drugi to jego priorytet
sizer.AddGrowableRow(1, 2)

panel.SetSizer(sizer)

frame.Show()
app.MainLoop()
