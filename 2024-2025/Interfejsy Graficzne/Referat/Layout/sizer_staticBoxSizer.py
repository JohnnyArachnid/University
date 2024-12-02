import wx

app = wx.App()

frame = wx.Frame(None, title="Sizer StaticBoxSizer Przykład", size=(400, 300))

panel = wx.Panel(frame)

# Tworzymy sizer typu StaticBox z tytułem
static_box = wx.StaticBox(panel, label="Grupa przycisków")

# Tworzymy sizer typu StaticBoxSizer w orientacji pionowej z StaticBoxem wewnątrz
sizer = wx.StaticBoxSizer(static_box, wx.VERTICAL)
# Możliwe utworzenie StaticBoxSizera bez StaticBoxa wewnątrz, należy wówczas przekazać kontener wyższego poziomu np. panel
# sizer = wx.StaticBoxSizer(wx.VERTICAL, panel, label="Grupa przycisków")

button1 = wx.Button(panel, label="Przycisk 1")
button2 = wx.Button(panel, label="Przycisk 2")
button3 = wx.Button(panel, label="Przycisk 3")

sizer.Add(button1, 1, wx.ALIGN_RIGHT | wx.ALL, 5)
sizer.Add(button2, 0, wx.ALIGN_CENTER | wx.TOP, 10)
sizer.Add(button3, 1, wx.EXPAND | wx.LEFT | wx.RIGHT, 20)

panel.SetSizer(sizer)

frame.Show()
app.MainLoop()
