import wx

app = wx.App()

frame = wx.Frame(None, title="Sizer GridBagSizer Przykład", size=(400, 300))

panel = wx.Panel(frame)

# Tworzymy sizer typu GridBagSizer z odstępami o wartości 5 pikseli w pionie i poziomie
sizer = wx.GridBagSizer(5, 5)

button1 = wx.Button(panel, label="Przycisk 1")
button2 = wx.Button(panel, label="Przycisk 2")
button3 = wx.Button(panel, label="Przycisk 3")
button4 = wx.Button(panel, label="Przycisk 4")
button5 = wx.Button(panel, label="Przycisk 5")

# Zmodyfikowana metoda dodawania
# Modyfikacji podlega parametr rozciągania, tutaj korzystamy z pos oraz span
# pos to pozycja danego elementu w siatce
# span to wartość kolejno wierszy oraz kolumn które zajmuje on w siatce
sizer.Add(button1, pos=(0, 0), span=(1, 1), flag=wx.EXPAND | wx.ALL, border=5)
sizer.Add(button2, (0, 1), (1, 2), wx.EXPAND | wx.ALL, 5)
sizer.Add(button3, (1, 0), (1, 1), wx.EXPAND | wx.ALL, 5)
sizer.Add(button4, (1, 1), (2, 1), wx.EXPAND | wx.ALL, 5)
sizer.Add(button5, (2, 2), (1, 1), wx.EXPAND | wx.ALL, 5)

# Ustawiamy, aby kolumny i wiersze automatycznie dostosowywały się do rozmiaru
# Drugi wiersz rośnie, gdy zmienia się rozmiar okna
# Argumentem dla AddGrowableRow w GridBagSizer jest tylko numer danego wiersza który ma podlegać rozciąganiu
sizer.AddGrowableRow(1)
# Trzecia kolumna rośnie, gdy zmienia się rozmiar okna
# Argumentem dla AddGrowableRow w AddGrowableCol jest tylko numer danej kolumny która ma podlegać rozciąganiu
sizer.AddGrowableCol(2)  

panel.SetSizer(sizer)

frame.Show()
app.MainLoop()
