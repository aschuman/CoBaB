<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.1" language="en_US">
<context>
    <name>ConfigData</name>
    <message>
        <location filename="core/src/ConfigData.cpp" line="74"/>
        <source>Bibliothek:
Enthält die zuletzt verwendeten Datensätze und die Datensätze aus dem Standardordner, der per Kommandozeile übergeben werden kann.
Per Doppelklick wird der Datensatz ausgewählt, in dem sich das Bild/Video befindet, das als Grundlage für die inhaltsbasierte Suche dienen soll. 
 
Viewer:
Über die Buttons &apos;vorheriges&apos; und &apos;nächstes&apos; wird das Bild/Video ausgewählt, das als Grundlage für die inhaltsbasierte Suche dienen soll. 
Bei einem Rechtsklick auf das Bild werden die verfügbaren Suchalgorithmen aufgelistet. Fährt man mit der Maus über einen solchen Algorithmus, erscheint eine Beschreibung zu diesem. Durch Klicken auf einen Algorithmus kann mit dem Programm fortgefahren werden. 
In den Bildern werden außerdem, falls vorhanden, Annotationen angezeigt. 
Nach einem Klick auf den Button &apos;Bereich auswählen&apos; kann ein eigenes Rechteck auf dem Bild gezogen werden. Mit einem Rechtsklick in die Annotation oder das gezogene Rechteck werden die dafür verfügbaren Algorithmen angezeigt. 

Parameter:
Nach der Auswahl eines Algorithmus kann man Parameter für diesen festlegen. Außerdem können weitere Datensätze ausgewählt werden, in denen gesucht werden soll. 
 
Bestätigung:
Hier wird die aktuelle Auswahl angezeigt, die dem Algorithmus übergeben wird. 
 
Ergebnisse:
Die Bilder können als positiv (grüner Kasten, ein Klick auf das Bild), negativ (roter Kasten, zweiter Klick) oder wieder neutral (dritter Klick) bewertet werden.
Durch einen Klick auf den Button &apos;Erneut suchen&apos; wird das Feedback an den Algorithmus übermittelt und eine neue verbesserte Suche gestartet.</source>
        <translation>Library:
It shows the last used datasets and the datasets which are in a folder delivered by command line.
The dataset with the photo/video which will be used for the content based search can be selected by double clicking the dataset.

Mediaviewer:
The photo/video which will be used for the content based search can be selected by using the &apos;previous&apos; and &apos;next&apos; buttons.
A right click on the image will show the available algorithms. The description of the algorithms is shown by a mouse over.
The program can be continued by clicking on an algorithm.
The viewer shows available annotations in the photos. After clicking the button &apos;select ROI&apos; it is possible to create an own rectangle over the photo. By right-clicking in the annotation or drawn rectangle the available algorithms are shown.

Parameters:
After choosing an algorithm it is possible to set parameters for this algorithm. Moreover additional datases (search domain) can be chosen.

Confirmation:
It shows the values which will be given to the search algorithm.

Search Results:
The photos can be marked as positive (green box, one click on the photo), negative (red box, second click on the photo) or neutral again (third click).
By clicking the button &apos;search again&apos; the feedback is submitted to the algorithm and a new and better search is started.</translation>
    </message>
    <message>
        <location filename="core/src/ConfigData.cpp" line="95"/>
        <source>CoBaB ermöglicht es, anhand eines ausgewählten Bildes oder Videos eine inhaltsbasierte Suche in Bild- oder Videodaten durchzuführen. Als Ergebnis liefert CoBaB eine Auswahl ähnlicher Bilder oder Videos. Durch die Eingabe von Feedback kann diese Auswahl verfeinert werden.

Autoren: Anja Blechinger, Marie Bommersheim, Georgi Georgiev, Tung Nguyen, Vincent Winkler, Violina Zhekova</source>
        <translation>CoBaB provides content based search in photo or video data. Based on a chosen photo it shows similar photos or videos. This result can be improved by giving feedback.

Authors: Anja Blechinger, Marie Bommersheim, Georgi Georgiev, Tung Nguyen, Vincent Winkler, Violina Zhekova</translation>
    </message>
</context>
<context>
    <name>ConfirmationPageWidget</name>
    <message>
        <location filename="core/ui/ConfirmationPageWidget.ui" line="14"/>
        <location filename="core/src/ConfirmationPageWidget.cpp" line="211"/>
        <source>CoBaB - Bestätigung</source>
        <translation>CoBaB - Confirmation</translation>
    </message>
    <message>
        <location filename="core/ui/ConfirmationPageWidget.ui" line="46"/>
        <source>ausgewählter Suchbereich</source>
        <translation>chosen photo</translation>
    </message>
    <message>
        <location filename="core/ui/ConfirmationPageWidget.ui" line="53"/>
        <source>start search</source>
        <translation>start search</translation>
    </message>
    <message>
        <location filename="core/src/ConfirmationPageWidget.cpp" line="20"/>
        <location filename="core/src/ConfirmationPageWidget.cpp" line="197"/>
        <source>Suche starten</source>
        <translation>start search</translation>
    </message>
    <message>
        <location filename="core/src/ConfirmationPageWidget.cpp" line="25"/>
        <location filename="core/src/ConfirmationPageWidget.cpp" line="198"/>
        <source>Datenordner</source>
        <translation>datasets</translation>
    </message>
    <message>
        <location filename="core/src/ConfirmationPageWidget.cpp" line="26"/>
        <location filename="core/src/ConfirmationPageWidget.cpp" line="199"/>
        <source>Algorithmus</source>
        <translation>algorithm</translation>
    </message>
    <message>
        <location filename="core/src/ConfirmationPageWidget.cpp" line="27"/>
        <location filename="core/src/ConfirmationPageWidget.cpp" line="200"/>
        <source>Parameter</source>
        <translation>parameters</translation>
    </message>
    <message>
        <location filename="core/src/ConfirmationPageWidget.cpp" line="113"/>
        <location filename="core/src/ConfirmationPageWidget.cpp" line="202"/>
        <source>Bild kann nicht geöffnet werden.</source>
        <translation>Photo cannot be opened.</translation>
    </message>
</context>
<context>
    <name>LibraryPageWidget</name>
    <message>
        <location filename="core/ui/LibraryPageWidget.ui" line="14"/>
        <location filename="core/src/LibraryPageWidget.cpp" line="41"/>
        <source>CoBaB - Bibliothek</source>
        <translation>CoBaB - Library</translation>
    </message>
    <message>
        <location filename="core/src/LibraryPageWidget.cpp" line="68"/>
        <source>Datenordner öffnen</source>
        <translation>Open Dataset</translation>
    </message>
    <message>
        <location filename="core/src/LibraryPageWidget.cpp" line="88"/>
        <source>Kein gültiger Datenordner gewählt</source>
        <translation>No valid dataset chosen</translation>
    </message>
</context>
<context>
    <name>MainWindow</name>
    <message>
        <location filename="core/ui/MainWindow.ui" line="14"/>
        <source>CoBaB</source>
        <translation>CoBaB</translation>
    </message>
    <message>
        <location filename="core/ui/MainWindow.ui" line="40"/>
        <location filename="core/src/MainWindow.cpp" line="163"/>
        <source>Datei</source>
        <translation>File</translation>
    </message>
    <message>
        <location filename="core/ui/MainWindow.ui" line="49"/>
        <location filename="core/src/MainWindow.cpp" line="169"/>
        <source>Einstellungen</source>
        <translation>Settings</translation>
    </message>
    <message>
        <location filename="core/ui/MainWindow.ui" line="66"/>
        <location filename="core/ui/MainWindow.ui" line="126"/>
        <location filename="core/src/MainWindow.cpp" line="164"/>
        <source>Hilfe</source>
        <translation>Help</translation>
    </message>
    <message>
        <location filename="core/ui/MainWindow.ui" line="80"/>
        <location filename="core/ui/MainWindow.ui" line="102"/>
        <source>toolBar</source>
        <translation></translation>
    </message>
    <message>
        <location filename="core/ui/MainWindow.ui" line="131"/>
        <location filename="core/src/MainWindow.cpp" line="78"/>
        <location filename="core/src/MainWindow.cpp" line="161"/>
        <source>Über CoBaB</source>
        <translation>About CoBaB</translation>
    </message>
    <message>
        <location filename="core/ui/MainWindow.ui" line="136"/>
        <location filename="core/src/MainWindow.cpp" line="149"/>
        <location filename="core/src/MainWindow.cpp" line="173"/>
        <source>Ton einschalten</source>
        <translation>sound on</translation>
    </message>
    <message>
        <location filename="core/ui/MainWindow.ui" line="149"/>
        <location filename="core/src/MainWindow.cpp" line="166"/>
        <source>Deutsch</source>
        <translation>German</translation>
    </message>
    <message>
        <location filename="core/ui/MainWindow.ui" line="141"/>
        <source>Datensatz öffnen</source>
        <translation>open dataset</translation>
    </message>
    <message>
        <location filename="core/src/MainWindow.cpp" line="79"/>
        <location filename="core/src/MainWindow.cpp" line="90"/>
        <source>Schließen</source>
        <translation>Close</translation>
    </message>
    <message>
        <location filename="core/src/MainWindow.cpp" line="89"/>
        <location filename="core/src/MainWindow.cpp" line="162"/>
        <source>Hilfe für CoBaB</source>
        <translation>Help for CoBaB</translation>
    </message>
    <message>
        <location filename="core/src/MainWindow.cpp" line="151"/>
        <location filename="core/src/MainWindow.cpp" line="171"/>
        <source>Ton ausschalten</source>
        <translation>sound off</translation>
    </message>
    <message>
        <location filename="core/ui/MainWindow.ui" line="53"/>
        <location filename="core/src/MainWindow.cpp" line="165"/>
        <source>Sprache</source>
        <translation>Language</translation>
    </message>
    <message>
        <location filename="core/ui/MainWindow.ui" line="157"/>
        <location filename="core/src/MainWindow.cpp" line="167"/>
        <source>Englisch</source>
        <translation>English</translation>
    </message>
    <message>
        <location filename="core/src/MainWindow.cpp" line="168"/>
        <source>Datenordner öffnen</source>
        <translation>Open Dataset</translation>
    </message>
</context>
<context>
    <name>ParameterPageWidget</name>
    <message>
        <location filename="core/ui/ParameterPageWidget.ui" line="14"/>
        <location filename="core/src/ParameterPageWidget.cpp" line="105"/>
        <source>CoBaB - Parameter</source>
        <translation>CoBaB - Parameters</translation>
    </message>
    <message>
        <location filename="core/ui/ParameterPageWidget.ui" line="20"/>
        <location filename="core/src/ParameterPageWidget.cpp" line="96"/>
        <source>Verfahrensparameter</source>
        <translation>Parameters</translation>
    </message>
    <message>
        <location filename="core/ui/ParameterPageWidget.ui" line="37"/>
        <location filename="core/src/ParameterPageWidget.cpp" line="97"/>
        <source>Auswahl des Suchraums</source>
        <translation>Selection of search area</translation>
    </message>
    <message>
        <location filename="core/ui/ParameterPageWidget.ui" line="78"/>
        <source>next</source>
        <translation>next</translation>
    </message>
    <message>
        <location filename="core/src/ParameterPageWidget.cpp" line="95"/>
        <source>Weiter</source>
        <translation>next</translation>
    </message>
</context>
<context>
    <name>PhotoViewer</name>
    <message>
        <location filename="core/src/PhotoViewer.cpp" line="49"/>
        <source>Foto </source>
        <translation>Photo </translation>
    </message>
    <message>
        <location filename="core/src/PhotoViewer.cpp" line="49"/>
        <source> von </source>
        <translation> of </translation>
    </message>
</context>
<context>
    <name>QJsonModel</name>
    <message>
        <location filename="core/src/QJsonModel.cpp" line="32"/>
        <source>Parameter</source>
        <translation>Parameter</translation>
    </message>
    <message>
        <location filename="core/src/QJsonModel.cpp" line="33"/>
        <source>Wert</source>
        <translation>Value</translation>
    </message>
</context>
<context>
    <name>ResultsPageWidget</name>
    <message>
        <location filename="core/ui/ResultsPageWidget.ui" line="14"/>
        <location filename="core/src/ResultsPageWidget.cpp" line="238"/>
        <source>CoBaB - Ergebnisse</source>
        <translation>CoBaB - Results</translation>
    </message>
    <message>
        <location filename="core/ui/ResultsPageWidget.ui" line="88"/>
        <source>Erneut Suchen</source>
        <translation>search again</translation>
    </message>
    <message>
        <location filename="core/src/ResultsPageWidget.cpp" line="230"/>
        <source>Erneut suchen</source>
        <translation>search again</translation>
    </message>
</context>
<context>
    <name>SingleFrameVideoViewer</name>
    <message>
        <location filename="core/src/SingleFrameVideoViewer.cpp" line="206"/>
        <source>Video </source>
        <translation>Video </translation>
    </message>
    <message>
        <location filename="core/src/SingleFrameVideoViewer.cpp" line="206"/>
        <source> von </source>
        <translation> of </translation>
    </message>
</context>
<context>
    <name>ViewerPageWidget</name>
    <message>
        <location filename="core/ui/ViewerPageWidget.ui" line="14"/>
        <location filename="core/src/ViewerPageWidget.cpp" line="354"/>
        <source>CoBaB - Viewer</source>
        <translation>CoBaB - Viewer</translation>
    </message>
    <message>
        <location filename="core/ui/ViewerPageWidget.ui" line="63"/>
        <source>select ROI</source>
        <translation>select ROI</translation>
    </message>
    <message>
        <location filename="core/ui/ViewerPageWidget.ui" line="82"/>
        <source>-</source>
        <translation>-</translation>
    </message>
    <message>
        <location filename="core/ui/ViewerPageWidget.ui" line="101"/>
        <source>+</source>
        <translation>+</translation>
    </message>
    <message>
        <location filename="core/ui/ViewerPageWidget.ui" line="108"/>
        <source>100 %</source>
        <translation>100 %</translation>
    </message>
    <message>
        <location filename="core/ui/ViewerPageWidget.ui" line="194"/>
        <source>0</source>
        <translation>0</translation>
    </message>
    <message>
        <location filename="core/ui/ViewerPageWidget.ui" line="204"/>
        <source>TextLabel</source>
        <translation></translation>
    </message>
    <message>
        <location filename="core/src/ViewerPageWidget.cpp" line="324"/>
        <location filename="core/src/ViewerPageWidget.cpp" line="343"/>
        <source>Bereich entfernen</source>
        <translation>remove ROI</translation>
    </message>
    <message>
        <location filename="core/src/ViewerPageWidget.cpp" line="328"/>
        <location filename="core/src/ViewerPageWidget.cpp" line="345"/>
        <source>Bereich auswählen</source>
        <translation>select ROI</translation>
    </message>
</context>
</TS>
