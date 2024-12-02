import wx

app = wx.App()

frame = wx.Frame(None, title="Sizer BoxSizer Przykład", size=(400, 300))

panel = wx.Panel(frame)

# Tworzymy sizer typu BoxSizer, który będzie układał elementy pionowo wx.VERTICAL
sizer = wx.BoxSizer(wx.VERTICAL)
# Można utworzyć w ramach układu poziomego
# sizer = wx.BoxSizer(wx.HORIZONTAL)

# Dodajemy przyciski (`wx.Button`) do panelu
button1 = wx.Button(panel, label="Przycisk 1")
button2 = wx.Button(panel, label="Przycisk 2")
button3 = wx.Button(panel, label="Przycisk 3")

# Dodajemy przycisk 1 do sizer-a:
# button1: obiekt, który chcemy dodać do sizer-a
# 1: proporcja rozciągania (1 oznacza, że przycisk zajmie część dostępnej przestrzeni w ramach sizer-a)
# wx.ALIGN_RIGHT | wx.ALL: Flagi określające sposób rozmieszczania elementu
#   - wx.ALIGN_RIGHT: przycisk jest wyrównany do prawej w poziomie
#   - wx.ALL: dodaje margines wokół elementu z wszystkich stron
# 5: margines w pikselach (5 pikseli wokół przycisku)
sizer.Add(button1, 1, wx.ALIGN_RIGHT | wx.ALL, 5)
# Dodajemy przycisk 2 do sizer-a:
# 0: proporcja rozciągania (0 oznacza, że przycisk nie będzie się rozciągał)
# wx.ALIGN_CENTER | wx.TOP: Flagi rozmieszczania
#   - wx.ALIGN_CENTER: przycisk jest wyrównany do środka w poziomie
#   - wx.TOP: margines od góry (nie dodajemy marginesu z innych stron)
# 10: margines od góry w pikselach
sizer.Add(button2, 0, wx.ALIGN_CENTER | wx.TOP, 10)
# Dodajemy przycisk 3 do sizer-a:
# 1: proporcja rozciągania (przycisk będzie się rozciągał w dostępnej przestrzeni)
# wx.EXPAND | wx.LEFT | wx.RIGHT: Flagi rozmieszczania
#   - wx.EXPAND: rozciąga przycisk na całą szerokość
#   - wx.LEFT | wx.RIGHT: marginesy po lewej i prawej stronie
# 20: margines po lewej i prawej stronie w pikselach
sizer.Add(button3, 1, wx.EXPAND | wx.LEFT | wx.RIGHT, 20)

# Łączymy sizer z panelem, aby elementy były odpowiednio rozmieszczone
panel.SetSizer(sizer)

frame.Show()
app.MainLoop()