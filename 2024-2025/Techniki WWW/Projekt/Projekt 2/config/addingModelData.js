const Article = require('../models/Article.js');
const Comic_announcement = require('../models/Comic_announcement.js');
const Character_wiki = require('../models/Character_wiki.js');

const addMultipleArticles = async () => {
  const articlesData = [
    {
      title: "Oficjalny zwiastun serialu: Your Friendly Neighborhood Spider-Man",
      title_ang: "Official Trailer for the Series: Your Friendly Neighborhood Spider-Man",
      tag: ["Popularne", "Newsy", "Filmy"],
      tag_ang: ["Popular", "News", "Films"],
      content: "Możemy już obejrzeć pełny zwiastun serialu animowanego Your Friendly Neighborhood Spider-Man.\nRówny miesiąc przed premierą serialu w serialu zadebiutował pełny zwiastun serialu animowanego Your Friendly Neighborhood Spider-Man. Produkcja ta trafi na platformę Disney+ już 29 stycznia.\nPierwszy sezon serialu będzie składał się z 10 odcinków. W obsadzie głosowej znaleźli się Hudson Thames jako Peter Parker, Colman Domingo jako Norman Osborn, Zeno Robinson jako Harry Osborn, Charlie Cox jako Matt Murdock/Daredevil, Hugh Dancy jako Otto Octavius/Dr Octopus, Grace Song jako Nico Minoru i Eugene Byrd jako Lonnie Lincoln/Tombstone.",
      content_ang: "We can now watch the full trailer for the animated series Your Friendly Neighborhood Spider-Man.\nExactly one month before the series premiere, the full trailer for the animated series Your Friendly Neighborhood Spider-Man debuted on the series. The production will hit the Disney+ platform on January 29.\nThe first season of the series will consist of 10 episodes. The voice cast includes Hudson Thames as Peter Parker, Colman Domingo as Norman Osborn, Zeno Robinson as Harry Osborn, Charlie Cox as Matt Murdock/Daredevil, Hugh Dancy as Otto Octavius/Dr. Octopus, Grace Song as Nico Minoru, and Eugene Byrd as Lonnie Lincoln/Tombstone.",
      author: 'Administrator',
      number: 1,
      creation_date: "2025-01-20"
    },
    {
      title: "New Champions – czas na kolejną młodzieżową drużynę superbohaterów",
      title_ang: "New Champions – time for another youth superhero team",
      tag: ["Popularne", "Newsy", "Komiksy"],
      tag_ang: ["Popular", "News", "Comics"],
      content: "New Champions to kolejna komiksowa drużyna złożona w pełni z nastoletnich superbohaterów, która zyskała swoją własną serię komiksową.\nW komiksowym uniwersum Marvela znalazło się już miejsce dla sporej ilości drużyn superbohaterskich złożonych z nastoletnich bohaterów. Teraz do Young Avengers, New Mutants, New Warriors, Champions i Runaways dołączył kolejny zespół zwany New Champions. Pierwszy numer ich serii komiksowej New Champions #1 autorstwa Steve’a Foxe’a, Ivana Fiorelliego, IG Guary, Arthura Hesliego i Travisa Lanhama trafił do sprzedaży w Stanach Zjednoczonych 8 stycznia.",
      content_ang: "New Champions is another comic book team made up entirely of teenage superheroes who are getting their own comic book series.\nThe Marvel comic book universe already has a lot of teenage superhero teams. Now, the Young Avengers, New Mutants, New Warriors, Champions, and Runaways have been joined by another team called New Champions. The first issue of their comic book series, New Champions #1 by Steve Foxe, Ivan Fiorelli, IG Guara, Arthur Heslie, and Travis Lanham, went on sale in the United States on January 8.",
      author: 'Administrator',
      number: 2,
      creation_date: "2025-01-10"
    },
    {
      title: "Spin-offowe uniwersum Sony (na razie) się kończy",
      title_ang: "Sony's spin-off universe is (for now) coming to an end",
      tag: ["Popularne", "Plotki", "Filmy"],
      tag_ang: ["Popular", "Rumours", "Films"],
      content: "Uniwersum spin-offów od Sony dobiega końca. Przynajmniej na ten moment.\nKraven Łowca to kolejna produkcja w dziwacznym uniwersum spin-offów Sony skupionym wokół postaci powiązanych z komiksowym Spider-Manem, która prawdopodobnie zaliczy srogą porażkę finansową. Film w serwisie Rotten Tomatoes ma zaledwie 15% pozytywnych recenzji od krytyków i na razie zarobił jedynie 26 milionów dolarów przy około 100-milionowym budżecie. Po równie kiepskim wyniku Madame Web oraz zakończeniu trylogii o Venomie możemy się spodziewać, że Sony przynajmniej na jakiś czas odłoży dalsze plany na budowanie tego uniwersum do zamrażarki.\nTak przynajmniej twierdzi Umberto Gonzalez z serwisu The Wrap, który zacytował jednego ze znanych agentów talentów, który miał mu powiedzieć, że studio na ten moment zrobiło to, co chciało w tym temacie zrobić i w najbliższym czasie chce skupić się przede wszystkim na kolejnych filmach o Spider-Manie współtworzonych z Disneyem, a także na ostatniej części animowanej trylogii Spider-Verse.",
      content_ang: "The Sony spin-off universe is coming to an end. At least for now.\nKraven the Hunter is the latest in Sony's bizarre Spider-Man spin-off universe that will likely flop financially. The film has a mere 15% positive rating from critics on Rotten Tomatoes and has so far grossed just $26 million on a roughly $100 million budget. After the similarly poor performance of Madame Web and the conclusion of the Venom trilogy, we can expect Sony to put its plans for this universe on the ice for now.\nAt least that's what The Wrap's Umberto Gonzalez says, citing a well-known talent agent who told him that the studio has done what it wanted to do with the series so far and will focus on more Spider-Man films with Disney, as well as the final installment of the animated Spider-Verse trilogy.",
      author: "Moderator",
      number: 3,
      creation_date: "2024-12-25"
    },
    {
      title: "Tajemniczy aktor na planie: Fantastycznej Czwórki",
      title_ang: "Mystery Actor on the Set of: Fantastic Four",
      tag: ["Popularne", "Plotki", "Filmy"],
      tag_ang: ["Popular", "Rumours", "Films"],
      content: "Na planie Fantastycznej Czwórki w hiszpańskim Oviedo pojawił się tajemniczy aktor. Kto to może być?\nChoć zdjęcia do filmu Fantastyczna Czwórka powoli dobiegają końca, ekipa filmowa aktualnie pracuje na planie w hiszpańskim Oviedo. Dwa dni temu jedna z osób znajdujących się w okolicy zdołała uchwycić na krótkim wideo moment, w którym pracownik planu szybko przeprowadzał między samochodami aktora z twarzą ukrytą pod kocem.\nJako że zdjęcia członków głównej obsady w kostiumach pojawiały się już w sieci niejednokrotnie, od razu pojawiły się spekulacje, iż to aktor, którego udział w filmie nie został jeszcze ujawniony opinii publicznej. Najczęstszym przypuszczeniem było, że może to być Robert Downey Jr., który mógłby pojawić się w filmie jako cameo w nowej roli Doktora Dooma.\nFilm Fantastyczna Czwórka trafi do kin 25 lipca 2025 roku.",
      content_ang: "A mysterious actor has appeared on the set of Fantastic Four in Oviedo, Spain. Who could it be?\nAlthough filming for the Fantastic Four movie is slowly coming to an end, the film crew is currently working on the set in Oviedo, Spain. Two days ago, one of the people who was in the area managed to capture on a short video the moment when a set worker quickly led the actor between cars with his face hidden under a blanket.\nSince photos of the main cast members in costumes have already appeared on the web many times, speculation immediately arose that it was an actor whose participation in the film has not yet been revealed to the public. The most common assumption was that it could be Robert Downey Jr., who could appear in the film as a cameo in a new role as Doctor Doom.\nThe Fantastic Four movie will hit theaters on July 25, 2025.",
      author: "Administrator",
      number: 4,
      creation_date: "2024-12-12"
    },
    {
      title: "Amazing Spider-Man: Królewski okup (Tom 13) - Recenzja",
      title_ang: "Amazing Spider-Man: King's Ransom (Volume 13) - Review",
      tag: ["Popularne", "Recenzje", "Komiksy"],
      tag_ang: ["Popular", "Reviews", "Comics"],
      content: "W końcu los się uśmiechnął i sprawił, że w moje ręce wpadł komiks Amazing Spider-Man: Królewski okup. Przyznam szczerze, że dawno nie czytałam żadnej opowieści z Pajączkiem w głównej roli, dlatego z tym większą radością, oczywiście dzięki uprzejmości wyd. Egmont Polska, wzięłam się za lekturę tego komiksu. Czy warto było się ekscytować?\nFabuła komiksu jest prościutka. Spider-Man zaprzyjaźnia się z Bumerangiem i wspólnie walczą w pogoni na czas z przestępczym półświatkiem pod dowództwem Wilsona Fiska, żeby zdobyć pewne magiczne tablice, których moc może zagrozić światu. W międzyczasie J. Jonah Jameson prowadzi swoją kampanię promującą Pajączka w social mediach próbując udowodnić, że papierowa gazeta umiera i zostaliśmy opętani przez różne appki. W tle toczy się też wątek zakazanej miłości, który okazał się naprawdę przezabawny.\nOpowiadanie przeczytałam bardzo szybciutko i z miejsca dałam się wciągnąć. Historia jest bardzo prościutka, przyjemna i wręcz idealna na chłodny niedzielny wieczór przy herbatce rozgrzewającej. Pajączka oczywiście nie da się nie lubić, a jego rozmyślania czyta się równie przyjemnie co pozostałe dialogi w dymkach. Podoba mi się też przedstawienie social mediów jako ogłupiającego narzędzia, żeby tylko nabić sobie lajki albo być w centrum uwagi za wszelką cenę. Nie wiem czy taki był oryginalny zamysł Nicka Spencera, ale bardzo subtelnie i ciekawie poruszył tę tematykę.\nPozycja godna polecenia, idealna dla nowych czytelników.",
      content_ang: "Finally, fate smiled and made me get my hands on the comic Amazing Spider-Man: Royal Ransom. I honestly admit that I haven't read any stories with Spider-Man in the main role for a long time, so I took up reading this comic with even greater joy, of course thanks to the courtesy of the publisher Egmont Polska. Was it worth getting excited?\nThe plot of the comic is very simple. Spider-Man befriends Boomerang and together they fight in a time-consuming chase with the criminal underworld led by Wilson Fisk to obtain certain magic tablets, the power of which can threaten the world. In the meantime, J. Jonah Jameson runs his campaign promoting Spider-Man on social media, trying to prove that the paper newspaper is dying and we have been possessed by various apps. In the background, there is also a story of forbidden love, which turned out to be really hilarious.\nI read the story very quickly and got sucked in immediately. The story is very simple, pleasant and perfect for a cold Sunday evening with a warming tea. Of course, you can't help but like the little spider, and his musings are just as enjoyable to read as the other dialogues in the bubbles. I also like the presentation of social media as a mind-numbing tool, just to get likes or be the center of attention at all costs. I don't know if that was Nick Spencer's original intention, but he touched on this subject very subtly and interestingly.\nA recommended book, perfect for new readers.",
      author: "Moderator",
      number: 5,
      creation_date: "2024-12-03"
    },
    {
      title: "Marvel Rivals - Rozpiska aktualizacji / Roadmapa z contentem",
      title_ang: "Marvel Rivals - Update Schedule / Content Roadmap",
      tag: ["Newsy", "Gry"],
      tag_ang: ["News", "Games"],
      content: "Gracze Marvel Rivals wreszcie otrzymali rozpiskę aktualizacji i zaplanowanego contentu, na którą czekali tuż przed premierą nowej gry Marvela.\nRozpiska ta nie tylko przedstawia plany dotyczące samego wydania gry w grudniu, ale także tego, co wydarzy się później. Ponieważ Marvel Rivals to w zasadzie strzelanka z bohaterami w opakowaniu superbohaterskiej fabuły, nowi bohaterowie są naturalnie na czołowej pozycji na liście oczekiwań graczy. Nic więc dziwnego, że twórcy mieli sporo do powiedzenia na temat bohaterów, którzy pojawią się przy premierze, a także tych, którzy zostaną dodani, gdy system sezonowy będzie w pełnym rozkwicie.\nNa chwilę obecną wiemy o 27 bohaterach, którzy na pewno pojawią się w Marvel Rivals. Wśród nich znajdują się: Adam Warlock, Black Panther, Captain America, Doctor Strange, Groot, Hela, Hulk, Iron Man, Jeff the Land Shark (który był całkiem sporym zaskoczeniem), Loki, Luna Snow, Magik, Magneto, Mantis, Moon Knight, Namor, Peni Parker, Psylocke, Rocket Raccoon, Scarlet Witch, Spider-Man, Star-Lord, Storm, The Punisher, Thor, Venom i Winter Soldier. W rozpisce dla Marvel Rivals potwierdzono, że początkowy roster postaci będzie liczył 33 bohaterów, więc przed premierą pozostaje jeszcze sześciu do ujawnienia.",
      content_ang: "Marvel Rivals players finally got the update and content roadmap they’ve been waiting for just before the new Marvel game launches.\nThe roadmap not only details the game’s December release, but also what’s coming after. Since Marvel Rivals is essentially a hero shooter wrapped in a superhero storyline, new heroes are naturally at the top of players’ lists. It’s no surprise then that the developers had a lot to say about the heroes that will be coming at launch, as well as those that will be added once the seasonal system is in full swing.\nAt this point, we know of 27 heroes that are definitely coming to Marvel Rivals. These include: Adam Warlock, Black Panther, Captain America, Doctor Strange, Groot, Hela, Hulk, Iron Man, Jeff the Land Shark (who was quite the surprise), Loki, Luna Snow, Magik, Magneto, Mantis, Moon Knight, Namor, Peni Parker, Psylocke, Rocket Raccoon, Scarlet Witch, Spider-Man, Star-Lord, Storm, The Punisher, Thor, Venom, and Winter Soldier. The Marvel Rivals roster confirms that the initial character roster will consist of 33 heroes, so there are still six more to be revealed before launch.",
      author: "Administrator",
      number: 6,
      creation_date: "2024-11-29"
    },
    {
      title: "Denzel Washington wystąpi w Czarnej Panterze 3",
      title_ang: "Denzel Washington to star in Black Panther 3",
      tag: ["Plotki", "Filmy"],
      tag_ang: ["Rumours", "Films"],
      content: "Podczas jednego z udzielonych ostatnio wywiadów Denzel Washington potwierdził, że wystąpi w Czarnej Panterze 3 w nieznanej roli.\nDenzel Washington jest obecnie w trasie promującej jego najnowszy film Gladiator 2. Podczas wizyty w Australii aktor udzielił wywiadu miejscowej stacji telewizyjnej, w którym rozmawiał o przyszłości swojej kariery i wspomniał, że ma zamiar wystąpić w Czarnej Panterze 3 i że będzie to jedna z ostatnich ról w jego karierze przed planowaną emeryturą. Na ten moment nie wiadomo jednak, w kogo miałby się wcielić\nDenzel Washington to niespełna 70-letni amerykański aktor, reżyser i producent. W trakcie swojej wieloletniej i bardzo owocnej kariery filmowej i scenicznej, podczas której łączył występy w filmach akcji, dramatach i szekspirowskich adaptacjach, został ponad 80 razy nominowany do różnych nagród. Ma na koncie dwa Oscary za role w filmach Chwała i Dzień próby. Obecnie można go oglądać w kinach w roli Makrynusa w filmie Gladiator 2.",
      content_ang: "In a recent interview, Denzel Washington confirmed that he will appear in Black Panther 3 in an undisclosed role.\nDenzel Washington is currently on tour promoting his latest film Gladiator 2. During his visit to Australia, the actor gave an interview to a local TV station, in which he talked about the future of his career and mentioned that he will be appearing in Black Panther 3 and that it will be one of his last roles before his planned retirement. At the moment, however, it is not known who he will be playing\nDenzel Washington is an almost 70-year-old American actor, director and producer. During his long and very fruitful film and stage career, during which he has combined appearances in action films, dramas and Shakespearean adaptations, he has been nominated for over 80 awards. He has two Oscars under his belt for his roles in Glory and Training Day. He can currently be seen in cinemas as Macrinus in Gladiator 2.",
      author: "Administrator",
      number: 7,
      creation_date: "2024-11-20"
    },
    {
      title: "Venom: The Last Dance (2024) - Recenzja",
      title_ang: "Venom: The Last Dance (2024) - Review",
      tag: ["Recenzje", "Filmy"],
      tag_ang: ["Reviews", "Films"],
      content: "Film przeciętny, ale czy na pewno?\nCóż, pierwsze odczucie po seansie Venom: The Last Dance? Dobrze się na nim bawiłem, ale czegoś mi w nim brakowało. Jednak im dłużej się nad nim zastanawiałem tym bardziej dochodziłem do wniosku, iż trzecia cześć w moim mniemaniu jest dobrym filmem. Tyle wstępu, tak więc zapraszam do mojej recenzji ostatniego tańca z czarnym symbiontem. Miłej lektury.\nPo wydarzeniach z drugiej części, czyli Venom: Let There Be Carnage i chwilowym pobycie na Ziemi-616 (scena po napisach w filmie Spider-Man: No Way Home), Eddie i Venom lądują na swojej Ziemi w małym barze, gdzie dowiadują się, że ściga ich policja. Tak więc wyjęci spod prawa, próbują dotrzeć do Nowego Yorku, aby oczyścić się z zarzutów. Niestety, po drodze okazuje się nie tylko policją muszą się martwić, ale także wojskiem jak i wysłannikami boga symbiontów, który pragnie zemsty za uwięzienie go na wieki, a przy tym klucza do wolności.\nI tutaj zaczyna się mój pierwszy problem całego filmu… Otóż, dlaczego Knull został wprowadzony już teraz? Po co? Jaki był w tym cel? W komiksach pojawił się on po dekadach od debiutu Venoma, za to dla Sony wystarczyły dwie części i „Bang”, lecimy z grubej rury. Podejrzewam, że po klapie części z Carnagem, dla studia najlepszym wyborem był wątek, który w komiksach odniósł tak duży sukces, bo w sumie dlaczego z niego nie skorzystać i zarobić kasę? Istnieje jeszcze fakt, że mamy tu kuriozalną przepaść historyczną pomiędzy wydarzeniami, ale to przecież nie jest już ważne. Niemniej, jest jakieś światełko w tym szaleństwie, gdyż ostatecznie Knull nie został uwolniony i miejmy nadzieję, że reżyserzy oraz studio na trochę go zostawią, eksplorując inne wątki ze świata Venoma.\nKolejny problem jaki mam z tą produkcją to bardzo nierówne tempo. Przeplatanie scen akcji z powolnymi (przegadanymi) momentami wyglądało jak odpalanie silnika ze starym akumulatorem na mrozie, który ostatecznie zaskakuje, by w końcu gdzieś tam nas dowieźć. Jest to jakieś podejście, ale ja jednakowoż wolę, gdy akcja rozkręca się wolniej lub szybciej, ale rozwija się spójnie i regularnie aż do wielkiego finału. Mimo wszystko, jest to film superbohaterski. Ma on głównie dostarczać rozrywki, czego faktycznie i o dziwo udaje mu się dokonać.\nMam mieszane uczucia ale do polecenia.",
      content_ang: "The movie is average, but is it really?\nWell, the first impression after watching Venom: The Last Dance? I had a good time, but something was missing. However, the longer I thought about it, the more I came to the conclusion that the third part is a good movie in my opinion. That's all for the introduction, so I invite you to my review of the last dance with the black symbiote. Enjoy reading.\nAfter the events of the second part, Venom: Let There Be Carnage and a short stay on Earth-616 (the post-credits scene in Spider-Man: No Way Home), Eddie and Venom land on their Earth in a small bar, where they learn that the police are after them. So, outlaws, they try to get to New York to clear themselves of the charges. Unfortunately, along the way it turns out that it's not only the police they have to worry about, but also the army and the emissaries of the symbiote god, who wants revenge for imprisoning him forever, and at the same time the key to freedom.\nAnd here begins my first problem with the whole film... So, why was Knull introduced now? Why? What was the purpose? In the comics, he appeared decades after Venom's debut, but for Sony, two parts and 'Bang' were enough, we're off. I suspect that after the flop of the part with Carnage, the best choice for the studio was the storyline that was so successful in the comics, because after all, why not use it and make money? There is also the fact that we have a bizarre historical gap between the events, but that's not important anymore. Nevertheless, there is some light in this madness, because in the end Knull was not released and let's hope that the directors and the studio will leave him for a while, exploring other threads from the world of Venom.\nAnother problem I have with this production is the very uneven pacing. Interspersing action scenes with slow (talked about) moments looked like starting an engine with an old battery in the cold, which eventually starts, to finally get us somewhere. It's some approach, but I prefer when the action starts slower or faster, but develops coherently and regularly until the big finale. After all, this is a superhero movie. It is mainly supposed to provide entertainment, which it actually and surprisingly manages to do.\nI have mixed feelings, but I recommend it.",
      author: "Administrator",
      number: 8,
      creation_date: "2024-11-09"
    },
    {
      title: "Marvel United: Multiverse & Civil War (Gry planszowe) - Recenzja",
      title_ang: "Marvel United: Multiverse & Civil War (Board games) - Review",
      tag: ["Recenzje", "Gry"],
      tag_ang: ["Review", "Games"],
      content: "Marvel United: Multiverse Nieskończone światy, nieskończone możliwości.\nSeria gier planszowych Marvel United, stworzona przez wydawnictwa CMON oraz Spin Master (w Polsce wydawana przez Portal Games), przenosi graczy do dynamicznego świata superbohaterów Marvela. To kooperacyjne gry, w których gracze wspólnie stawiają czoła złoczyńcom w klimacie komiksowego uniwersum. W Polsce tytuły z tej serii są wydawane przez Portal Games. Najnowsze edycje — Marvel United: Multiverse i Marvel United: Civil War — rozbudowują podstawową grę, wprowadzając świeże mechaniki oraz nowe wyzwania i historie, które odzwierciedlają popularne wątki komiksowe.\nMarvel United: Multiverse to rozszerzenie, które zabiera graczy w podróż przez alternatywne wersje rzeczywistości Marvela. W tej edycji motywem przewodnim jest koncepcja multiwersum, co pozwala na spotkanie alternatywnych wersji znanych bohaterów. W grze znajdziemy nowych herosów, takich jak Spider-Man 2099, Captain Carter czy Ironheart, oraz antagonistów z innych wymiarów (Emperor Doom, Immortus czy Maestro), co zapewnia większą różnorodność podczas rozgrywki.\nMechanicznie Multiverse wprowadza nowości, takie jak alternatywne wersje postaci, różniące się zdolnościami i strategiami walki. Niektórzy złoczyńcy posiadają zdolności wpływające na różne wymiary, co wymaga planowania na większą skalę. Wizualnie gra zachowuje charakterystyczny dla serii styl komiksowy z dopracowanymi figurkami bohaterów i złoczyńców. Ta edycja szczególnie przypadnie do gustu fanom bardziej rozbudowanego świata Marvela i graczom, którzy cenią sobie większą złożoność w strategii.",
      content_ang: "Marvel United: Multiverse Infinite worlds, infinite possibilities.\nThe Marvel United board game series, created by CMON and Spin Master (published in Poland by Portal Games), takes players to the dynamic world of Marvel superheroes. These are cooperative games in which players jointly face villains in the atmosphere of the comic book universe. In Poland, the titles in this series are published by Portal Games. The latest editions - Marvel United: Multiverse and Marvel United: Civil War - expand the basic game, introducing fresh mechanics and new challenges and stories that reflect popular comic book plots.\nMarvel United: Multiverse is an expansion that takes players on a journey through alternate versions of Marvel reality. In this edition, the main theme is the concept of the multiverse, which allows you to meet alternate versions of famous heroes. The game features new heroes, such as Spider-Man 2099, Captain Carter and Ironheart, as well as antagonists from other dimensions (Emperor Doom, Immortus and Maestro), which provides greater variety during gameplay.\nMechanically, Multiverse introduces new features, such as alternate versions of characters with different abilities and combat strategies. Some villains have abilities that affect different dimensions, which requires planning on a larger scale. Visually, the game retains the series' characteristic comic book style with refined figurines of heroes and villains. This edition will especially appeal to fans of the more extensive Marvel universe and players who value greater complexity in strategy.",
      author: "Moderator",
      number: 9,
      creation_date: "2024-10-30"
    },
    {
      title: "Magik #1 (2025) – Recenzja",
      title_ang: "Magik #1 (2025) – Review",
      tag: ["Recenzje", "Komiksy"],
      tag_ang: ["Review", "Comics"],
      content: "Magiczny start!\nW sumie można zastanawiać się czy ten zeszyt to na pewno komiks o Magik, czy może jest ona dodatkiem do historii kogoś innego, ale… No właśnie, nie ma to większego znaczenia. Magik #1 jest dobrym komiksem. Ma swoje minusy, ale to, jak się go czyta i ogląda sprawia, że czytelnika nic one nie obchodzą. Czy potrzeba lepszych słów zachęty?\nDo tej pory Ashley Allen niemal nie istniała w branży. Coś tam zrobiła dla Marvel Zombies: Black, White & Blood i zeszyt X-Men: Blood Hunt – Magik, ale nie pamiętam tych jej prac. Zrobiły na mnie raczej niewielkie wrażenie. Teraz jednak ją zapamiętam, bo zrobiła tu kawał dobrej roboty i chętnie poczytam więcej jej komiksów, jak już coś zrobi.\nNo i oddaje, ten komiks ma wielkie szczęście, że dostał go w swoje ręce Peralta, bo ten gość jest jednym z najlepszych, jakich Marvel ma obecnie w swoich szeregach. Gość ma świetna kreska, wyrazisty styl i jeszcze ten kolor… Klimat, dynamika, emocje, wszystko to jest tutaj. A dzięki współpracy jego i Allen Magik zalicza tu prawdziwie magiczny start.",
      content_ang: "Magical start!\nIn fact, one may wonder whether this issue is really a comic about Magik, or maybe she is an addition to someone else's story, but... Well, it doesn't really matter. Magik #1 is a good comic. It has its flaws, but the way it is read and watched makes the reader not care about them. Do you need better words of encouragement?\nUntil now, Ashley Allen has almost not existed in the industry. She did something for Marvel Zombies: Black, White & Blood and the X-Men: Blood Hunt issue - Magik, but I don't remember those works of hers. They made rather little impression on me. Now, however, I will remember her, because she did a great job here and I will gladly read more of her comics when she does something.\nAnd I give it to you, this comic is very lucky that Peralta got his hands on it, because this guy is one of the best that Marvel currently has in its ranks. The guy has great lines, a distinctive style and then that color... Atmosphere, dynamics, emotions, all of that is here. And thanks to his and Allen's cooperation, Magik is making a truly magical start here.",
      author: "Administrator",
      number: 10,
      creation_date: "2024-10-22"
    },
    {
      title: "Deadpool/Wolverine #1 (2025) – Recenzja",
      title_ang: "Deadpool/Wolverine #1 (2025) – Review",
      tag: ["Recenzje", "Komiksy"],
      tag_ang: ["Review", "Comics"],
      content: "Deadverine!\nWolvie i Deadpol. Byli w komiksach, byli w filmie, teraz przez ten film znów razem w komiksach brylują. Zbędnie. Może gdyby pisał to ktoś inny, niż Percy, zeszyt miałby sens, tak jednak znów dostajemy tę samą miałkość, co zawsze. Nic nowego, nic świeżego i jak na komiks z tytułem zaczynającym się od Deadpoola, samego Najemnika z nawijką jest w nim zdecydowanie za mało. Oto komiks Deadpool/Wolverine #1.\nFajna okładka, niezła szata graficzna i niewiele poza tym. Znów dostajemy komiks pretekstowy, który w zasadzie mógł nie powstać, bo niczego nie wnosi. Prosta historia, prosto skrojone postacie… Percy skupia się tu na dwóch rzeczach: akcji i Wolviem. I gdyby zrobił to dobrze, byłoby fajnie, ale nie. Akcja jest nijaka, jak z gry komputerowej i nic w niej nie angażuje. Sztuczna, sztywna, wysilona. Co do Wolviego zaś mamy bohatera, który jest samograjem, ale nie w takich historiach.\nCo tu nie gra? Wolvie może i ma potencjał komediowy, ale niewielu umie go wykorzystać. Tu trzeba subtelności, a Percy to gość, który ma jej mniej więcej tyle, ile gość z baseballem w ręku. I takie są jego postacie. Nie gra to kontrastem, a że zbyt wiele komediowego tonu nie pasuje tu do kreacji Wolviego, mniej jest Deadpoola, który tę komedie podkreśla. I tak wszystko to staje się coraz bardziej nijakie. O niebo słabsze od filmu. Tyle w temacie.",
      content_ang: "Deadverine!\nWolvie and Deadpol. They were in the comics, they were in the movie, now because of this movie they are shining together in comics again. Unnecessarily. Maybe if someone other than Percy wrote it, the issue would make sense, but as it is we get the same shallowness as always. Nothing new, nothing fresh and for a comic with a title starting with Deadpool, there is definitely too little of the Merc with a hook. Here is the comic Deadpool/Wolverine #1.\nA nice cover, good graphics and not much else. Once again we get a pretext comic that could have never been created, because it brings nothing. A simple story, simply cut characters... Percy focuses on two things here: action and Wolvie. And if he did it well, it would be cool, but no. The action is bland, like from a computer game and nothing in it is engaging. Artificial, stiff, strained. As for Wolvie, we have a character who is a natural, but not in stories like this.\nWhat's wrong here? Wolvie may have comedic potential, but few know how to use it. It requires subtlety, and Percy is a guy who has about as much of it as a guy with a baseball in his hand. And that's how his characters are. It doesn't play with contrast, and since too much of the comedic tone doesn't fit Wolvie's creation, there's less Deadpool to emphasize the comedy. And so it all becomes more and more bland. Way weaker than the movie. That's all there is to it.",
      author: "Moderator",
      number: 11,
      creation_date: "2024-10-14"
    },
    {
      title: "What If…? [Sezon 3 / 2024] - Recenzja",
      title_ang: "What If…? [Sezon 3 / 2024] - Review",
      tag: ["Recenzje", "Filmy"],
      tag_ang: ["Review", "Films"],
      content: "What If…? [Sezon 3 / 2024].\nWhat If…?, długoletnia seria komiksów Marvela, to jeden z najbardziej kreatywnych i eksperymentalnych tytułów w repertuarze firmy. Każdy numer przedstawia postacie Marvela w nowych, alternatywnych realiach, eksplorując kluczowe wybory, które mogły zmienić bieg historii. Animowana adaptacja serialowa od Marvel Studios/Marvel Television, wchodząca w trzeci sezon, wiernie kontynuuje ten styl narracji, dostarczając nam niespodziewanych i często zabawnych scenariuszy z udziałem bohaterów znanych z właściwego kinowo-serialowego Marvel Cinematic Universe.\nW odcinkach, które wylądowały na platformie Disney+ możemy zobaczyć niezwykłe przygody w alternatywnych rzeczywistościach. Przyszli Avengersi walczą w gigantycznych mechach przeciwko Hulkowi w wersji Kaiju, a ich maszyny łączą się w najpotężniejszego robota w historii – ewidentna inspiracja Power Rangers/Super Sentai. W innym odcinku Agatha Harkness występuje w musicalu z lat 40. wraz z Kingo (Eternals), co okazuje się sprytnym planem do rzucenia zaklęcia. Z kolei Red Guardian powstrzymuje Zimowego Żołnierza przed zabiciem Starków, po czym obaj wyruszają na wspólną przygodę. Nie mniej szalona jest historia nowożeńców, a mianowicie Kaczora Howarda i Darcy Lewis, którzy udają się na międzygalaktyczny rejs, ścigani przez złoczyńców pragnących zdobyć ich jeszcze niewyklute dziecko. Tu warto dodać, że dużym plusem jest to, że (tak jak w poprzednich sezonach) głosy bohaterom nadal podkładają aktorzy znani z MCU, jak Mark Ruffalo (Hulk) czy Oscar Isaac (Moon Knight).\nPodsumowując, jeśli podobały Ci się wcześniejsze sezony What If…?, trzeci sezon również przypadnie Ci do gustu. Dla fanów MCU to prawdziwa gratka, pełna kreatywnych, zaskakujących historii i niezapomnianych momentów. Twórcom udało się po raz kolejny pokazać, że multiwersum może być pełne świeżości i humoru, a każdy odcinek stanowi wyjątkowe przeżycie. Dzięki świetnej obsadzie głosowej i odważnym pomysłom narracyjnym, serial udowadnia, że alternatywne historie Marvela wciąż potrafią bawić, wzruszać i inspirować.",
      content_ang: "What If…? [Season 3 / 2024].\nWhat If…?, the long-running Marvel comic book series, is one of the most creative and experimental titles in the company's repertoire. Each issue presents Marvel characters in new, alternate realities, exploring key choices that could have changed the course of history. The animated series adaptation from Marvel Studios/Marvel Television, entering its third season, faithfully continues this style of storytelling, delivering unexpected and often hilarious scenarios featuring characters known from the proper cinematic and TV Marvel Cinematic Universe.\nIn the episodes that landed on the Disney+ platform, we can see extraordinary adventures in alternate realities. Future Avengers fight in giant mechs against the Kaiju version of the Hulk, and their machines combine into the most powerful robot in history - a clear inspiration from Power Rangers/Super Sentai. In another episode, Agatha Harkness performs in a 1940s musical with Kingo (Eternals), which turns out to be a clever plan to cast a spell. In turn, Red Guardian stops the Winter Soldier from killing the Starks, and the two of them set off on an adventure together. No less crazy is the story of newlyweds, namely Howard the Duck and Darcy Lewis, who go on an intergalactic cruise, pursued by villains who want to get their unhatched child. It is worth adding here that a big plus is that (as in previous seasons) the voices of the characters are still provided by actors known from the MCU, such as Mark Ruffalo (Hulk) and Oscar Isaac (Moon Knight).\nTo sum up, if you liked the previous seasons of What If...?, you will also like the third season. For fans of the MCU, it is a real treat, full of creative, surprising stories and unforgettable moments. The creators have managed to show once again that the multiverse can be full of freshness and humor, and each episode is a unique experience. With a great voice cast and bold narrative ideas, the series proves that alternative Marvel stories can still entertain, move and inspire.",
      author: "Moderator",
      number: 12,
      creation_date: "2024-10-06"
    },
  ];

  try {
    await Article.bulkCreate(articlesData);
    console.log('Articles have been added to database.');
  } catch (error) {
    console.error('Error while adding articles:', error);
  }
};

const addMultipleComicAnnouncement = async () => {
  const comicAnnouncementData = [
    {
      title: "Kaczogród. Atak robotów i inne historie z lat 1964-1966",
      title_ang: "Duckburg. Robot Attack and Other Stories from 1964-1966",
      release_date: "2025-01-22",
      expectations: "60",
      number: 1,
    },
    {
      title: "Batman. Łowy",
      title_ang: "Batman. The hunt",
      release_date: "2025-01-22",
      expectations: "80",
      number: 2,
    },
    {
      title: "X-Men. Punkty zwrotne. Pieśń egzekutora",
      title_ang: "X-Men. Turning Points. The Executioner's Song",
      release_date: "2025-01-10",
      expectations: "95",
      number: 3,
    },
    {
      title: "Ronin",
      title_ang: "Ronin",
      release_date: "2024-12-30",
      expectations: "100",
      number: 4,
    },
    {
      title: "Rządy X. X-Men. Tom 2",
      title_ang: "Reign of X. X-Men. Volume 2",
      release_date: "2025-01-03",
      expectations: "55",
      number: 5,
    },
    {
      title: "Amazing Spider-Man. Spisek Kameleona. Tom 14",
      title_ang: "Amazing Spider-Man. The Chameleon Conspiracy. Volume 14",
      release_date: "2024-12-07",
      expectations: "100",
      number: 6,
    },
    {
      title: "Star Wars. Darth Vader. Mroczne droidy. Tom 8",
      title_ang: "Star Wars. Darth Vader. Dark Droids. Volume 8",
      release_date: "2024-11-29",
      expectations: "90",
      number: 7,
    },
    {
      title: "Smerfy i fioletowa fasola. Tom 35",
      title_ang: "The Smurfs and the Purple Bean. Volume 35",
      release_date: "2024-11-20",
      expectations: "40",
      number: 8,
    },
    {
      title: "Przygody Supermana. Jon Kent",
      title_ang: "Adventures of Superman. Jon Kent",
      release_date: "2024-10-30",
      expectations: "75",
      number: 9,
    },
    {
      title: "Mali bogowie. Kreteńska zabawa. Tom 11",
      title_ang: "Little Gods. Cretan Fun. Volume 11",
      release_date: "2024-12-15",
      expectations: "30",
      number: 10,
    },
    {
      title: "Asteriks u Brytów. Tom 8",
      title_ang: "Asterix among the Britons. Volume 8",
      release_date: "2025-02-26",
      expectations: "80",
      number: 11,
    },
    {
      title: "Star Wars. Mroczne droidy. Drużyna D",
      title_ang: "Star Wars. Dark Droids. D-Team",
      release_date: "2025-02-26",
      expectations: "75",
      number: 12,
    },
    {
      title: "Batman. Ziemia niczyja. Owoce ziemi. Tom 5",
      title_ang: "Batman. No Man's Land. Fruits of the Earth. Volume 5",
      release_date: "2025-03-26",
      expectations: "45",
      number: 13,
    },
    {
      title: "Kajtek i Koko. Zwariowana wyspa",
      title_ang: "Kajtek and Koko. Crazy Island",
      release_date: "2025-03-20",
      expectations: "60",
      number: 14,
    },
    {
      title: "Złowieszcza wojna",
      title_ang: "Sinister War",
      release_date: "2025-03-01",
      expectations: "90",
      number: 15,
    },
  ];

  try {
    await Comic_announcement.bulkCreate(comicAnnouncementData);
    console.log('Comic announcements have been added to database.');
  } catch (error) {
    console.error('Error while adding comic announcements:', error);
  }
};

const addMultipleCharacters = async () => {
  const charactersData = [
    {
      hero_name: "Człowiek Pająk",
      hero_name_ang: "Spider-Man",
      short_description: "Przyjazny superbohater z sąsiedztwa.",
      short_description_ang: "Your friendly neighborhood superhero.",
      real_name: "Peter Benjamin Parker",
      age: 25,
      description: "Peter Parker, znany jako Spider-Man, był zwykłym nastolatkiem, aż do momentu, gdy został ukąszony przez radioaktywnego pająka. Ta przypadkowa sytuacja dała mu nadludzkie zdolności, takie jak siła, zręczność i zdolność do wspinaczki po ścianach. Początkowo używał swoich mocy dla osobistego zysku, ale po tragicznej śmierci wujka Bena, Peter zrozumiał, że 'z wielką mocą wiąże się wielka odpowiedzialność'. Jako Spider-Man, walczy o sprawiedliwość, stając w obliczu licznych przeciwników, starając się jednocześnie prowadzić życie nastolatka.",
      description_ang: "Peter Parker, known as Spider-Man, was an ordinary teenager until he was bitten by a radioactive spider. This accidental event gave him superhuman abilities, such as strength, agility, and the ability to climb walls. Initially, he used his powers for personal gain, but after the tragic death of his Uncle Ben, Peter realized that 'with great power comes great responsibility.' As Spider-Man, he fights for justice, facing numerous adversaries while trying to live the life of a teenager.",
      abbilities: ["Superludzka siła", "Zwinność i refleks", "Przyczepność do ścian", "Szósty zmysł (Pająkowy zmysł)", "Wydzielanie sieci (pajęcza sieć)", "Wysoka inteligencja i umiejętności wynalazcy"],
      abbilities_ang: ["Superhuman Strength", "Agility and Reflexes", "Wall Adhesion", "Sixth Sense (Spider Sense)", "Web Secretion (Spider Web)", "High Intelligence and Inventor Skills"],
      number: 1,
    },
    {
      hero_name: "Człowiek z Żelaza",
      hero_name_ang: "Iron-Man",
      short_description: "Playboy oraz Miliarder, superbohater na marginesie.",
      short_description_ang: "Playboy and the Billionaire, a superhero on the margin.",
      real_name: "Anthony Edward 'Tony' Stark",
      age: 40,
      description: "Tony Stark, miliarder, geniusz, wynalazca i filantrop, został porwany przez terrorystów, którzy zmusili go do budowy broni masowego rażenia. Zamiast tego stworzył zbroję, która pozwoliła mu uciec i stać się superbohaterem. Później, jako Iron Man, poświęcał swoje życie, aby ratować świat przed zagrożeniami.",
      description_ang: "Tony Stark, a billionaire genius, inventor and philanthropist, was kidnapped by terrorists who forced him to build weapons of mass destruction. Instead, he created an armor that allowed him to escape and become a superhero. Later, as Iron Man, he devoted his life to saving the world from threats.",
      abbilities: ["Nosi zaawansowaną zbroję z wieloma funkcjami", "Superludzką siłę dzięki zbroi", "Zdolności lotu dzięki napędowi rakietowemu", "Zaawansowane umiejętności technologiczne", "Wysoka inteligencja i umiejętności wynalazcy"],
      abbilities_ang: ["Wears advanced armor with multiple functions", "Superhuman strength thanks to armor", "Rocket-powered flight capabilities", "Advanced technological skills", "High intelligence and inventor skills"],
      number: 2,
    },
    {
      hero_name: "Kapitan Ameryka",
      hero_name_ang: "Captain America",
      short_description: "Żywa legenda stanów zjednoczonych.",
      short_description_ang: "A living legend of the United States.",
      real_name: "Steven Grant Rogers",
      age: 115,
      description: "Steve Rogers był zwykłym mężczyzną, który marzył o walce o wolność swojego kraju. Po nieudanej próbie wstąpienia do armii, został wybrany do programu 'Superżołnierz', który dał mu nadludzką siłę i wytrzymałość. Jako Kapitan Ameryka, stał się symbolem nadziei dla ludzkości.",
      description_ang: "Steve Rogers was an ordinary man who dreamed of fighting for the freedom of his country. After an unsuccessful attempt to join the army, he was selected for the 'Super Soldier' ​​program, which gave him superhuman strength and endurance. As Captain America, he became a symbol of hope for humanity.",
      abbilities: ["Superludzka siła", "Zwinność i refleks", "Zaawansowane umiejętności w walce wręcz", "Niezłomna wola i morale", "Znakomita strategia i dowodzenie"],
      abbilities_ang: ["Superhuman Strength", "Agility and Reflexes", "Advanced Hand-to-Hand Combat Skills", "Unbreakable Will and Morale", "Superior Strategy and Command"],
      number: 3,
    },
    {
      hero_name: "Wolverine",
      hero_name_ang: "Wolverine",
      short_description: "Kanadyjczyk z bolesną i długą przeszłością.",
      short_description_ang: "A Canadian with a long and painful past.",
      real_name: "James Howlett",
      age: 150,
      description: "James Howlett, znany jako Wolverine, to mutant z regeneracyjnymi zdolnościami, który przeżył przez wieki, walcząc w wielu wojnach i konfliktach. Jego nieśmiertelność i nadludzkie zdolności czynią go jednym z najbardziej niebezpiecznych bohaterów.",
      description_ang: "James Howlett, known as Wolverine, is a mutant with regenerative abilities who has survived for centuries, fighting in many wars and conflicts. His immortality and superhuman abilities make him one of the most dangerous heroes.",
      abbilities: ["Superludzka siła", "Zwinność i refleks", "Regeneracja komórkowa", "Szponki wykonane z adamantium", "Superludzkie zmysły", "Niezwykła siła fizyczna"],
      abbilities_ang: ["Superhuman Strength", "Agility and Reflexes", "Cellular Regeneration", "Adamantium Claws", "Superhuman Senses", "Incredible Physical Strength"],
      number: 4,
    },
    {
      hero_name: "Czarna Wdowa",
      hero_name_ang: "Black Widow",
      short_description: "Wyszkolona zabójczyni po tej dobrej stronie.",
      short_description_ang: "A trained assassin on the good side.",
      real_name: "Natalia Alianovna Romanova",
      age: 40,
      description: "Natasza Romanoff, znana jako Czarna Wdowa, była kiedyś rosyjską szpiegiem, która przeszła przez szereg niebezpiecznych misji. Została wychowana w tajnej organizacji KGB i później, jako członkini Avengers, stała się jednym z najpotężniejszych agentów świata.",
      description_ang: "Natasha Romanoff, known as the Black Widow, was once a Russian spy who went through a series of dangerous missions. She was raised in the secret organization KGB and later, as a member of the Avengers, became one of the most powerful agents in the world.",
      abbilities: ["Zwinność i refleks", "Zaawansowane umiejętności w walce wręcz", "Zdolności szpiegowskie", "Zaawansowane umiejętności strzeleckie", "Wysoka inteligencja i spryt", "Niezwykła wytrzymałość i odporność na ból"],
      abbilities_ang: ["Agility and reflexes", "Advanced hand-to-hand combat skills", "Spying skills", "Advanced shooting skills", "High intelligence and cunning", "Extraordinary endurance and pain resistance"],
      number: 5,
    },
  ];

  try {
    await Character_wiki.bulkCreate(charactersData);
    console.log('Characters have been added to database.');
  } catch (error) {
    console.error('Error while adding characters:', error);
  }
};