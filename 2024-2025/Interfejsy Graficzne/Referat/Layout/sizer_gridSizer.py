import wx

app = wx.App()

frame = wx.Frame(None, title="Sizer GridSizer Przykład", size=(400, 300))

panel = wx.Panel(frame)

# Tworzymy sizer typu GridSizer z 2 wierszami i 3 kolumnami oraz odstępami o wartości 5 pikseli w pionie i poziomie
sizer = wx.GridSizer(2, 3, 5, 5)

button1 = wx.Button(panel, label="Przycisk 1")
button2 = wx.Button(panel, label="Przycisk 2")
button3 = wx.Button(panel, label="Przycisk 3")

# Grupowa definicja dodawanych elementów, u nas przycisków
buttons = [
    (wx.Button(panel, label="Przycisk 4"), 0, wx.EXPAND),
    (wx.Button(panel, label="Przycisk 5"), 0, wx.EXPAND),
    (wx.Button(panel, label="Przycisk 6"), 0, wx.EXPAND),
]

sizer.Add(button1, 0, wx.ALIGN_LEFT | wx.ALL, 5)
sizer.Add(button2, 1, wx.ALIGN_CENTER | wx.ALL, 5)
sizer.Add(button3, 0, wx.ALIGN_RIGHT | wx.ALL, 5)

# Dodajemy kolejne trzy przyciski za pomocą metody AddMany
sizer.AddMany(buttons)  

panel.SetSizer(sizer)

frame.Show()
app.MainLoop()
