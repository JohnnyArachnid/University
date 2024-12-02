# Importujemy bibliotekę wxPython, która jest używana do tworzenia aplikacji GUI.
import wx

# Tworzymy instancję klasy `wx.App`, która zarządza cyklem życia aplikacji i obsługuje zdarzenia.
app = wx.App()

# Tworzymy główne okno aplikacji (`wx.Frame`).
# `None` oznacza, że ramka nie ma nadrzędnego elementu (jest to główne okno aplikacji).
# `title` ustawia tytuł okna na "Absolute Positioning Przykład".
# `size` ustawia początkowy rozmiar okna na szerokość 400 pikseli i wysokość 300 pikseli.
frame = wx.Frame(None, title="Absolute Positioning Przykład", size=(400, 300))

# Tworzymy panel (`wx.Panel`) jako element podrzędny ramki (`frame`).
# Panel działa jako kontener dla innych elementów GUI, umożliwiając ich grupowanie.
panel = wx.Panel(frame)

# Umieszczamy etykiety tekstowe z wykorzystaniem pozycjonowania absolutnego.
# Tworzymy pierwszą etykietę tekstową (`wx.StaticText`) na panelu (`panel`).
# `label` określa tekst wyświetlany jako "Tekst 1".
# `pos` ustawia absolutną pozycję etykiety w panelu na punkt (50, 50).
label1 = wx.StaticText(panel, label="Tekst 1", pos=(50, 50))

# Tworzymy drugą etykietę tekstową z tekstem "Tekst 2".
# Pozycja ustawiona jest na (200, 50) – 200 pikseli od lewej krawędzi panelu i 50 pikseli od góry.
label2 = wx.StaticText(panel, label="Tekst 2", pos=(200, 50))

# Tworzymy trzecią etykietę tekstową z tekstem "Tekst 3".
# Pozycja etykiety to (125, 150), co oznacza, że jest 125 pikseli od lewej krawędzi panelu i 150 pikseli od góry.
label3 = wx.StaticText(panel, label="Tekst 3", pos=(125, 150))

# Wyświetlamy ramkę (główne okno aplikacji) na ekranie.
# Bez tej metody okno nie będzie widoczne.
frame.Show()

# Rozpoczynamy główną pętlę aplikacji GUI, która przetwarza zdarzenia użytkownika.
# Pętla działa w nieskończoność, dopóki użytkownik nie zamknie aplikacji.
app.MainLoop()
