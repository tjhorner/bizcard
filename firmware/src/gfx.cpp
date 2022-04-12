#include "gfx.h"
#include <string.h>

#define TEXT_SIZE_X 35
#define TEXT_SIZE_Y 23

#define PICTURE_SIZE_X 41
#define PICTURE_SIZE_Y 20

using namespace io;

namespace gfx {

void putChar(char ch, size_t x, size_t y)
{
    moveCursorTo(x, y);

    char str[2] = {ch, '\0'};
    writeString(str);
    refreshScreen();
}

void putText(const char *text, size_t x, size_t y, int number_of_chars = -1)
{
    size_t len = strlen(text);
    if (number_of_chars < 0)
        number_of_chars = len;

    for (int i = 0; i < number_of_chars; i++)
    {
        if (i < len)
            putChar(text[i], x + i, y);
        else
            putChar(' ', x + i, y);
    }
}

void typeText(const char *text, size_t x, size_t y, size_t before_delay, size_t inter_delay,
              size_t after_delay, char cursorCharacter = ' ')
{
    if (cursorCharacter != ' ')
        putChar(cursorCharacter, x, y);
    sleepFor(before_delay);

    moveCursorTo(x, y);

    size_t c = 0;
    while (text[c] != '\0')
    {
        if (cursorCharacter != ' ')
            putChar(cursorCharacter, x + c + 1, y);
        putChar(text[c], x + c, y);

        if (text[c] != ' ')
            sleepFor(inter_delay);

        c++;
    }

    sleepFor(after_delay);

    if (cursorCharacter != ' ')
        putChar(' ', x + c, y);
}

void clearRectangle(size_t x, size_t y, size_t sx, size_t sy)
{
    for (size_t i = y; i < y + sy; i++)
    {
        for (size_t j = x; j < x + sx; j++)
            putChar(' ', j, i);
    }
}

void drawPicture(const char *image, int X, int Y)
{
    size_t screenSizeX = getScreenSizeX();
    size_t screenSizeY = getScreenSizeY();

    if (X == -1)
        X = screenSizeX - PICTURE_SIZE_X;

    if (Y == -1)
        Y = screenSizeY - PICTURE_SIZE_Y;

    if (strcmp(image, "aperture") == 0)
    {
        putText("              .,-:;//;:=,               ", X, Y + 0, PICTURE_SIZE_X);
        putText("          . :H@@@MM@M#H/.,+%;,          ", X, Y + 1, PICTURE_SIZE_X);
        putText("       ,/X+ +M@@M@MM%=,-%HMMM@X/,       ", X, Y + 2, PICTURE_SIZE_X);
        putText("     -+@MM; $M@@MH+-,;XMMMM@MMMM@+-     ", X, Y + 3, PICTURE_SIZE_X);
        putText("    ;@M@@M- XM@X;. -+XXXXXHHH@M@M#@/.   ", X, Y + 4, PICTURE_SIZE_X);
        putText("  ,>MM@@MH ,@%=            .---=-=:=,.  ", X, Y + 5, PICTURE_SIZE_X);
        putText("  =@#@@@MX .,              -%HX$$%%%+;  ", X, Y + 6, PICTURE_SIZE_X);
        putText(" =-./@M@M$                  .;@MMMM@MM: ", X, Y + 7, PICTURE_SIZE_X);
        putText(" X@/.-$MM/                    .+MM@@@M$ ", X, Y + 8, PICTURE_SIZE_X);
        putText(",@M@H: :@:                    . =X#@@@@-", X, Y + 9, PICTURE_SIZE_X);
        putText(",@@@MMX, .                    /H- ;@M@M=", X, Y + 10, PICTURE_SIZE_X);
        putText(".H@@@@M@+,                    %MM+..%#$.", X, Y + 11, PICTURE_SIZE_X);
        putText(" /MMMM@MMH/.                  XM@MH, =; ", X, Y + 12, PICTURE_SIZE_X);
        putText("  /%+%$XHH@$=              , .H@@@@MX,  ", X, Y + 13, PICTURE_SIZE_X);
        putText("   .=--------.           -%H.,@@@@@MX,  ", X, Y + 14, PICTURE_SIZE_X);
        putText("   .%MM@@@HHHXX$$$%+- .:$MMX =M@@MM%.   ", X, Y + 15, PICTURE_SIZE_X);
        putText("     =XMMM@MM@MM#H;,-+HMM@M+ /MMMX=     ", X, Y + 16, PICTURE_SIZE_X);
        putText("       =%@M@M#@$-.=$@MM@@@M: %M<=       ", X, Y + 17, PICTURE_SIZE_X);
        putText("         ,:+$+-,/H#MMMMMMM@= =,         ", X, Y + 18, PICTURE_SIZE_X);
        putText("               =++%%%%+/:-              ", X, Y + 19, PICTURE_SIZE_X);
    }
    else if (strcmp(image, "explosion") == 0)
    {
        putText("            .+                          ", X, Y + 0, PICTURE_SIZE_X);
        putText("             /M.                        ", X, Y + 1, PICTURE_SIZE_X);
        putText("              H#@:              ,.      ", X, Y + 2, PICTURE_SIZE_X);
        putText("              -###H-          -@/       ", X, Y + 3, PICTURE_SIZE_X);
        putText("               %####$.  -;  .%#X        ", X, Y + 4, PICTURE_SIZE_X);
        putText("                M#####+;#H :M#M.        ", X, Y + 5, PICTURE_SIZE_X);
        putText("..          .+/;%#########X###-         ", X, Y + 6, PICTURE_SIZE_X);
        putText(" -/%H%+;-,    +##############/          ", X, Y + 7, PICTURE_SIZE_X);
        putText("    .:$M###MH$%+############X  ,--=;-   ", X, Y + 8, PICTURE_SIZE_X);
        putText("        -/H#####################H+=.    ", X, Y + 9, PICTURE_SIZE_X);
        putText("            +#################X.        ", X, Y + 10, PICTURE_SIZE_X);
        putText("         =%M####################H;.     ", X, Y + 11, PICTURE_SIZE_X);
        putText("            /@###############+;;/%%;,   ", X, Y + 12, PICTURE_SIZE_X);
        putText("         -%###################$.        ", X, Y + 13, PICTURE_SIZE_X);
        putText("       ;H######################M=       ", X, Y + 14, PICTURE_SIZE_X);
        putText("    ,%#####MH$%:+#####M###-/@####%      ", X, Y + 15, PICTURE_SIZE_X);
        putText("  :$H%+;=-      -####X.,M#   -+M##@-    ", X, Y + 16, PICTURE_SIZE_X);
        putText(" .              .###.    :      =$##+   ", X, Y + 17, PICTURE_SIZE_X);
        putText("                .#H,               :XH, ", X, Y + 18, PICTURE_SIZE_X);
        putText("                 +                   .:-", X, Y + 19, PICTURE_SIZE_X);
    }
    else if (strcmp(image, "atom") == 0)
    {
        putText("                 =/;;/-                 ", X, Y + 0, PICTURE_SIZE_X);
        putText("                +:    //                ", X, Y + 1, PICTURE_SIZE_X);
        putText("               /,      /:               ", X, Y + 2, PICTURE_SIZE_X);
        putText("              -X        H.              ", X, Y + 3, PICTURE_SIZE_X);
        putText(".//;;::;:-,   X=        :+   .-;:=;:;%;.", X, Y + 4, PICTURE_SIZE_X);
        putText("M-       ,=;;;#:,      ,:#;;:=,       ,@", X, Y + 5, PICTURE_SIZE_X);
        putText(":%           :%.=/++++/=.$=           %=", X, Y + 6, PICTURE_SIZE_X);
        putText(" ,%;         %/:+/:,,/++:+/         ;+. ", X, Y + 7, PICTURE_SIZE_X);
        putText("   ,+/.    ,;@+,        ,%H;,    ,/+,   ", X, Y + 8, PICTURE_SIZE_X);
        putText("      ;+;;/= @.  .H##X   -X :///+;      ", X, Y + 9, PICTURE_SIZE_X);
        putText("      ;+=;;;.@,  .XM@$.  =X.//;=%/.     ", X, Y + 10, PICTURE_SIZE_X);
        putText("   ,;:      :@%=        =$H:     .+%-   ", X, Y + 11, PICTURE_SIZE_X);
        putText(" ,%=         %;-///==///-//         =%, ", X, Y + 12, PICTURE_SIZE_X);
        putText(";+           :%-;;;;;;;;-X-           +:", X, Y + 13, PICTURE_SIZE_X);
        putText("@-      .-;;;;M-        =M/;;;-.      -X", X, Y + 14, PICTURE_SIZE_X);
        putText(" :;;::;;-.    %-        :+    ,-;;-;:== ", X, Y + 15, PICTURE_SIZE_X);
        putText("              /X        H..             ", X, Y + 16, PICTURE_SIZE_X);
        putText("               ./      %=               ", X, Y + 17, PICTURE_SIZE_X);
        putText("                //    +;                ", X, Y + 18, PICTURE_SIZE_X);
        putText("                 ,////,                 ", X, Y + 19, PICTURE_SIZE_X);
    }
    else if (strcmp(image, "radioactive") == 0)
    {
        putText("             =+$HM####@H%;,             ", X, Y + 0, PICTURE_SIZE_X);
        putText("          /H###############M$           ", X, Y + 1, PICTURE_SIZE_X);
        putText("          ,:################+           ", X, Y + 2, PICTURE_SIZE_X);
        putText("           .H##############+            ", X, Y + 3, PICTURE_SIZE_X);
        putText("             X############/             ", X, Y + 4, PICTURE_SIZE_X);
        putText("              $##########/              ", X, Y + 5, PICTURE_SIZE_X);
        putText("               %########/               ", X, Y + 6, PICTURE_SIZE_X);
        putText("                /X/;;+X/                ", X, Y + 7, PICTURE_SIZE_X);
        putText("                                        ", X, Y + 8, PICTURE_SIZE_X);
        putText("                 -XHHX-                 ", X, Y + 9, PICTURE_SIZE_X);
        putText("                ,######,                ", X, Y + 10, PICTURE_SIZE_X);
        putText("#############X  .M####M.  X#############", X, Y + 11, PICTURE_SIZE_X);
        putText("##############-   -//-.  -##############", X, Y + 12, PICTURE_SIZE_X);
        putText("X##############%.      .+##############X", X, Y + 13, PICTURE_SIZE_X);
        putText("-##############X        X##############-", X, Y + 14, PICTURE_SIZE_X);
        putText(" %############%          %############% ", X, Y + 15, PICTURE_SIZE_X);
        putText("  %##########,            ;##########%  ", X, Y + 16, PICTURE_SIZE_X);
        putText("   ;#######M=              =M#######.   ", X, Y + 17, PICTURE_SIZE_X);
        putText("    .+M###@,                ,@###M+.    ", X, Y + 18, PICTURE_SIZE_X);
        putText("       :XH.                  .HX:       ", X, Y + 19, PICTURE_SIZE_X);
    }
    else if (strcmp(image, "fire") == 0)
    {
        putText("                     -$-                ", X, Y + 0, PICTURE_SIZE_X);
        putText("                    .H##H.              ", X, Y + 1, PICTURE_SIZE_X);
        putText("                   +######+             ", X, Y + 2, PICTURE_SIZE_X);
        putText("                .+#########H.           ", X, Y + 3, PICTURE_SIZE_X);
        putText("              -$############@.          ", X, Y + 4, PICTURE_SIZE_X);
        putText("            =H###############@  -X:     ", X, Y + 5, PICTURE_SIZE_X);
        putText("          .$##################:  @#@-   ", X, Y + 6, PICTURE_SIZE_X);
        putText("     .;  .M###################;  H###:  ", X, Y + 7, PICTURE_SIZE_X);
        putText("   ;@#:  @###################@  ,#####: ", X, Y + 8, PICTURE_SIZE_X);
        putText(" -M###.  M#################@.  .######H ", X, Y + 9, PICTURE_SIZE_X);
        putText(" M####-  +###############$   =@#######X ", X, Y + 10, PICTURE_SIZE_X);
        putText(" H####$   -M###########+   :#########M. ", X, Y + 11, PICTURE_SIZE_X);
        putText("  /####X-   =########%   :M########@/.  ", X, Y + 12, PICTURE_SIZE_X);
        putText("    .;%H@X;   .$###X   :##MM@%+;:-      ", X, Y + 13, PICTURE_SIZE_X);
        putText("                 ..                     ", X, Y + 14, PICTURE_SIZE_X);
        putText("  -/;:-,.              ,,-==+M########H ", X, Y + 15, PICTURE_SIZE_X);
        putText(" -##################@HX%%+%%$%%%+:,,    ", X, Y + 16, PICTURE_SIZE_X);
        putText("    .-/H%%%+%%$H@###############M@+=:/+:", X, Y + 17, PICTURE_SIZE_X);
        putText("/XHX%:#####MH%=    ,---:;;;;/%%XHM,:###$", X, Y + 18, PICTURE_SIZE_X);
        putText("$@#MX %+;-                           .  ", X, Y + 19, PICTURE_SIZE_X);
    }
    else if (strcmp(image, "ok") == 0)
    {
        putText("                                      :X-", X, Y + 0, PICTURE_SIZE_X);
        putText("                                   :X### ", X, Y + 1, PICTURE_SIZE_X);
        putText("                                 ;@####@ ", X, Y + 2, PICTURE_SIZE_X);
        putText("                               ;M######X ", X, Y + 3, PICTURE_SIZE_X);
        putText("                             -@########$ ", X, Y + 4, PICTURE_SIZE_X);
        putText("                           .$##########@ ", X, Y + 5, PICTURE_SIZE_X);
        putText("                          =M############-", X, Y + 6, PICTURE_SIZE_X);
        putText("                         +##############$", X, Y + 7, PICTURE_SIZE_X);
        putText("                       .H############$=. ", X, Y + 8, PICTURE_SIZE_X);
        putText("          ,/:         ,M##########M,.    ", X, Y + 9, PICTURE_SIZE_X);
        putText("       -+@###;       =##########M;       ", X, Y + 10, PICTURE_SIZE_X);
        putText("    =%M#######;     :#########M/         ", X, Y + 11, PICTURE_SIZE_X);
        putText("-$M############;   :#########/           ", X, Y + 12, PICTURE_SIZE_X);
        putText(" ,;X############; =########$.            ", X, Y + 13, PICTURE_SIZE_X);
        putText("     ;H##########+#######M=              ", X, Y + 14, PICTURE_SIZE_X);
        putText("       .+###############+                ", X, Y + 15, PICTURE_SIZE_X);
        putText("          /M##########@-                 ", X, Y + 16, PICTURE_SIZE_X);
        putText("            ;M#######%                   ", X, Y + 17, PICTURE_SIZE_X);
        putText("              +#####;                    ", X, Y + 18, PICTURE_SIZE_X);
        putText("               ,$M-                      ", X, Y + 19, PICTURE_SIZE_X);
    }
    else if (strcmp(image, "blackmesa") == 0)
    {
        putText("           .-,+$XHHHHHHX$+;-.           ", X, Y + 0, PICTURE_SIZE_X);
        putText("        ,;X@@X%/.=----=:/%X@@X/,        ", X, Y + 1, PICTURE_SIZE_X);
        putText("      =$@@%=.              .=+H@X:      ", X, Y + 2, PICTURE_SIZE_X);
        putText("    -XMX:                      =XMX=    ", X, Y + 3, PICTURE_SIZE_X);
        putText("   /@@:                          =H@+   ", X, Y + 4, PICTURE_SIZE_X);
        putText("  %@X,                            .$@$  ", X, Y + 5, PICTURE_SIZE_X);
        putText(" +@X.                               $@% ", X, Y + 6, PICTURE_SIZE_X);
        putText("-@@.                                .@@=", X, Y + 7, PICTURE_SIZE_X);
        putText("%@%                                  +@$", X, Y + 8, PICTURE_SIZE_X);
        putText("H@:                                  :@H", X, Y + 9, PICTURE_SIZE_X);
        putText("H@:         :HHHHHHHHHHHHHHHHHHX,    =@H", X, Y + 10, PICTURE_SIZE_X);
        putText("%@%         ;@M@@@@@@@@@@@@@@@@@H-   +@$", X, Y + 11, PICTURE_SIZE_X);
        putText("=@@,        :@@@@@@@@@@@@@@@@@@@@@= .@@:", X, Y + 12, PICTURE_SIZE_X);
        putText(" +@X        :@@@@@@@@@@@@@@@M@@@@@@:%@% ", X, Y + 13, PICTURE_SIZE_X);
        putText("  $@$,      ;@@@@@@@@@@@@@@@@@M@@@@@@$. ", X, Y + 14, PICTURE_SIZE_X);
        putText("   +@@HHHHHHH@@@@@@@@@@@@@@@@@@@@@@@+   ", X, Y + 15, PICTURE_SIZE_X);
        putText("    =X@@@@@@@@@@@@@@@@@@@@@@@@@@@@X=    ", X, Y + 16, PICTURE_SIZE_X);
        putText("      :$@@@@@@@@@@@@@@@@@@@M@@@@$:      ", X, Y + 17, PICTURE_SIZE_X);
        putText("        ,;$@@@@@@@@@@@@@@@@@@X/-        ", X, Y + 18, PICTURE_SIZE_X);
        putText("           .-;+$XXHHHHHX$+;-.           ", X, Y + 19, PICTURE_SIZE_X);
    }
    else if (strcmp(image, "heart_broken") == 0)
    {
        putText("                          .,---.        ", X, Y + 0, PICTURE_SIZE_X);
        putText("                        ,/XM#MMMX;,     ", X, Y + 1, PICTURE_SIZE_X);
        putText("                      -%##########M%,   ", X, Y + 2, PICTURE_SIZE_X);
        putText("                     -@######%  $###@=  ", X, Y + 3, PICTURE_SIZE_X);
        putText("      .,--,         -H#######$   $###M: ", X, Y + 4, PICTURE_SIZE_X);
        putText("   ,;$M###MMX;     .;##########$;HM###X=", X, Y + 5, PICTURE_SIZE_X);
        putText(" ,/@##########H=      ;################+", X, Y + 6, PICTURE_SIZE_X);
        putText("-+#############M/,      %##############+", X, Y + 7, PICTURE_SIZE_X);
        putText("%M###############=      /##############:", X, Y + 8, PICTURE_SIZE_X);
        putText("H################      .M#############;.", X, Y + 9, PICTURE_SIZE_X);
        putText("@###############M      ,@###########M:. ", X, Y + 10, PICTURE_SIZE_X);
        putText("X################,      -$=X#######@:   ", X, Y + 11, PICTURE_SIZE_X);
        putText("/###################%-     +######$-    ", X, Y + 12, PICTURE_SIZE_X);
        putText(".;##################X     .X#####+,     ", X, Y + 13, PICTURE_SIZE_X);
        putText(" .;H################/     -X####+.      ", X, Y + 14, PICTURE_SIZE_X);
        putText("   ,;X##############,       .MM/        ", X, Y + 15, PICTURE_SIZE_X);
        putText("      ,:+$H@M#######M#$-    .$$=        ", X, Y + 16, PICTURE_SIZE_X);
        putText("           .,-=;+$@###X:    ;/=.        ", X, Y + 17, PICTURE_SIZE_X);
        putText("                  .,/X$;   .;:,         ", X, Y + 18, PICTURE_SIZE_X);
        putText("                      .,    ..          ", X, Y + 19, PICTURE_SIZE_X);
    }
    else if (strcmp(image, "heart") == 0)
    {
        putText("                     .,---.       ", X, Y + 0, PICTURE_SIZE_X);
        putText("                   ,/XM#MMMX;,    ", X, Y + 1, PICTURE_SIZE_X);
        putText("                 -%##########M%,  ", X, Y + 2, PICTURE_SIZE_X);
        putText("                -@#############@= ", X, Y + 3, PICTURE_SIZE_X);
        putText("      .,--,    -H###############M:", X, Y + 4, PICTURE_SIZE_X);
        putText("   ,;$M###MMX;.;#################X", X, Y + 5, PICTURE_SIZE_X);
        putText(" ,/@##########H=;################+", X, Y + 6, PICTURE_SIZE_X);
        putText("-+###############################+", X, Y + 7, PICTURE_SIZE_X);
        putText("%M###############################:", X, Y + 8, PICTURE_SIZE_X);
        putText("H###############################;.", X, Y + 9, PICTURE_SIZE_X);
        putText("@#############################M:. ", X, Y + 10, PICTURE_SIZE_X);
        putText("X############################@:   ", X, Y + 11, PICTURE_SIZE_X);
        putText("/############################$-   ", X, Y + 12, PICTURE_SIZE_X);
        putText(".;##########################+,    ", X, Y + 13, PICTURE_SIZE_X);
        putText(" .;H#######################+.     ", X, Y + 14, PICTURE_SIZE_X);
        putText("   ,;X##################H/        ", X, Y + 15, PICTURE_SIZE_X);
        putText("      ,:+$H@M##########$=         ", X, Y + 16, PICTURE_SIZE_X);
        putText("           .,-=;+$@###X:;         ", X, Y + 17, PICTURE_SIZE_X);
        putText("                  .,/X$;          ", X, Y + 18, PICTURE_SIZE_X);
        putText("                     .,           ", X, Y + 19, PICTURE_SIZE_X);
    }
    else if (strcmp(image, "cake") == 0)
    {
        putText("            ,:/+/-                      ", X, Y + 0, PICTURE_SIZE_X);
        putText("            /M/              .,-=.//.-  ", X, Y + 1, PICTURE_SIZE_X);
        putText("       .:/= ;MH/,    ,=/+%$XH@MM#@:     ", X, Y + 2, PICTURE_SIZE_X);
        putText("      -$##@+$###@H@MMM#######H:.    -/H#", X, Y + 3, PICTURE_SIZE_X);
        putText(" .,H@H@ X######@ -H#####@+-     -+H###@X", X, Y + 4, PICTURE_SIZE_X);
        putText("  .,@##H;      +XM##M/,     =%@###@X;-  ", X, Y + 5, PICTURE_SIZE_X);
        putText("X%-  :M##########$.    .:%M###@%:       ", X, Y + 6, PICTURE_SIZE_X);
        putText("M##H,   +H@@@$/-.  ,;$M###@%           -", X, Y + 7, PICTURE_SIZE_X);
        putText("M####M=,,---,.-%%H####M$:          ,+@##", X, Y + 8, PICTURE_SIZE_X);
        putText("@##################@/.         :%H##@$- ", X, Y + 9, PICTURE_SIZE_X);
        putText("M###############H,         ;HM##M$=     ", X, Y + 10, PICTURE_SIZE_X);
        putText("#################.    .=$M##M$=         ", X, Y + 11, PICTURE_SIZE_X);
        putText("################H..;XM##M$=          .:+", X, Y + 12, PICTURE_SIZE_X);
        putText("M###################@%=           =+@MH%", X, Y + 13, PICTURE_SIZE_X);
        putText("@################M/.          =+H#X%=   ", X, Y + 14, PICTURE_SIZE_X);
        putText("=+M##############M,       ,/X#X+;,      ", X, Y + 15, PICTURE_SIZE_X);
        putText("  .;XM##########H=    ,/X#H+:,          ", X, Y + 16, PICTURE_SIZE_X);
        putText("     .=+HM######M+/+HM@+=.              ", X, Y + 17, PICTURE_SIZE_X);
        putText("         ,:/%XM####H/.                  ", X, Y + 18, PICTURE_SIZE_X);
        putText("              ,.:=-.                    ", X, Y + 19, PICTURE_SIZE_X);
    }
    else if (strcmp(image, "glados") == 0)
    {
        putText("       #+ @      # #              M#@   ", X, Y + 0, PICTURE_SIZE_X);
        putText(" .    .X  X.%##@,# #   +@#######X. @#%  ", X, Y + 1, PICTURE_SIZE_X);
        putText("   ,==.   ,######M+  -#####%M####M-    #", X, Y + 2, PICTURE_SIZE_X);
        putText("  :H##M%:=##+ .M##M,;#####/+#######% ,M#", X, Y + 3, PICTURE_SIZE_X);
        putText(" .M########=  =@#@.=#####M=M#######=  X#", X, Y + 4, PICTURE_SIZE_X);
        putText(" :@@MMM##M.  -##M.,#######M#######. =  M", X, Y + 5, PICTURE_SIZE_X);
        putText("             @##..###:.    .H####. @@ X,", X, Y + 6, PICTURE_SIZE_X);
        putText("   ############: ###./####;  /##= @#. M ", X, Y + 7, PICTURE_SIZE_X);
        putText("           ,M## ,##,@#M;/M#M  @# X#% X# ", X, Y + 8, PICTURE_SIZE_X);
        putText(" %=   ######M## ##.M#:   ./#M ,M #M ,#$ ", X, Y + 9, PICTURE_SIZE_X);
        putText("##/         $## #+;#: #### ;#/ M M- @# :", X, Y + 10, PICTURE_SIZE_X);
        putText("#+ #M@MM###M-;M #:$#-##$H# .#X @ + $#. #", X, Y + 11, PICTURE_SIZE_X);
        putText("      ######/.: #%=# M#:MM./#.-#  @#: H#", X, Y + 12, PICTURE_SIZE_X);
        putText("+,.=   @###: /@ %#,@  ##@X #,-#@.##% .@#", X, Y + 13, PICTURE_SIZE_X);
        putText("#####+,/##/ @##  @#,+       /#M      X, ", X, Y + 14, PICTURE_SIZE_X);
        putText("   ,###M#@ M###H .#M-     ,##M  ;@@; ###", X, Y + 15, PICTURE_SIZE_X);
        putText("   .M#M##H ;####X ,@#######M/ -M###$  -H", X, Y + 16, PICTURE_SIZE_X);
        putText("    .M###%  X####H  .@@MM@;  .@#M@      ", X, Y + 17, PICTURE_SIZE_X);
        putText("      H#M    /@####/      ,++.  / ==-,  ", X, Y + 18, PICTURE_SIZE_X);
        putText("               ,=/:. .+X@MMH@#H  #####$=", X, Y + 19, PICTURE_SIZE_X);
    }
}

size_t currentCursorYPosition = 1;

void writeLine(const char *text, size_t after_delay, size_t inter_delay)
{
    typeText(text, 1, currentCursorYPosition, 0, inter_delay, after_delay, ' ');
    currentCursorYPosition++;
}

void clearArea()
{
    clearRectangle(1, 1, TEXT_SIZE_X, TEXT_SIZE_Y);
    currentCursorYPosition = 1;
}

void continueTune()
{
    // wait for other core to be ready
    rp2040.fifo.pop();

    // tell the other core to keep playing the song
    rp2040.fifo.push(1);
}

void main()
{
    initializeScreen();

    size_t screenSizeX = getScreenSizeX();
    size_t screenSizeY = getScreenSizeY();

    clearScreen();

    for (int y = 0; y < screenSizeY; y++)
    {
        for (int x = 0; x < screenSizeX; x++)
        {
            if ((y == 0) || ((y == screenSizeY - PICTURE_SIZE_Y - 1) && (x > screenSizeX - PICTURE_SIZE_X - 1)) ||
                ((y == screenSizeY - 1) && (x <= screenSizeX - PICTURE_SIZE_X - 1)))
                putChar('-', x, y);
            else if ((x == 0) || (x == screenSizeX - PICTURE_SIZE_X - 1) ||
                     ((x == screenSizeX - 1) && (y < screenSizeY - PICTURE_SIZE_Y)))
                putChar('|', x, y);
        }
    }

    putText("THANK YOU FOR PARTICIPATING", screenSizeX - PICTURE_SIZE_X,
            (screenSizeY - PICTURE_SIZE_Y) / 2 - 1);
    putText("IN THIS", screenSizeX - PICTURE_SIZE_X, (screenSizeY - PICTURE_SIZE_Y) / 2);
    putText("ENRICHMENT CENTER ACTIVITY!!", screenSizeX - PICTURE_SIZE_X,
            (screenSizeY - PICTURE_SIZE_Y) / 2 + 1);

    clearArea();
    writeLine("Forms FORM-29827281-12:", 0, 10);
    writeLine("Test Assessment Report", 0, 10);
    writeLine("", 100);
    writeLine("", 1100);

    continueTune(); // 0
    writeLine("This was a triumph.", 2000);

    continueTune(); // 1
    writeLine("I'm making a note here:", 200);
    writeLine("HUGE SUCCESS.", 1500, 120);

    continueTune(); // 2
    writeLine("It's hard to overstate", 0);
    writeLine("my satisfaction.", 3700);
    drawPicture("aperture");

    continueTune(); // 3
    writeLine("Aperture Science", 2200);

    continueTune(); // 4
    writeLine("We do what we must", 0);
    writeLine("because we can.", 2700);

    continueTune(); // 5
    writeLine("For the good of all of us.", 1200, 90);
    drawPicture("radioactive");

    continueTune(); // 6
    writeLine("Except the ones who are dead.", 420, 70);
    writeLine("", 100);

    continueTune(); // 7
    writeLine("But there's no sense crying", 0, 90);
    writeLine("over every mistake.", 500, 90);

    continueTune(); // 8
    writeLine("You just keep on trying", 0, 90);
    writeLine("till you run out of cake.", 300, 90);
    drawPicture("atom");

    continueTune(); // 9
    writeLine("And the Science gets done.", 0, 90);
    writeLine("And you make a neat gun.", 300, 90);
    drawPicture("aperture");

    continueTune(); // 10
    writeLine("For the people who are", 0, 90);
    writeLine("still alive.", 1500, 90);

    clearArea();

    writeLine("FORMS Form-55551-5:", 0, 10);
    writeLine("Personnel File Addendum:", 100, 10);
    writeLine("", 100);
    writeLine("Dear <<Subject Name Here>>,", 0);
    writeLine("", 100);

    continueTune(); // 11
    writeLine("I'm not even angry.", 2800);

    continueTune(); // 12
    writeLine("I'm being so sincere right now.", 2000);
    drawPicture("heart_broken");

    continueTune(); // 13
    writeLine("Even though you broke my heart.", 1100);
    writeLine("And killed me.", 2200);

    continueTune(); // 14
    drawPicture("explosion");
    writeLine("And tore me to pieces.", 2100);

    continueTune(); // 15
    drawPicture("fire");
    writeLine("And threw every piece into a fire.", 2200);

    continueTune(); // 16
    writeLine("As they burned it hurt because", 500);
    drawPicture("ok");
    writeLine("I was so happy for you!", 1000);

    continueTune(); // 17
    writeLine("Now these points of data", 0, 90);
    writeLine("make a beautiful line.", 0, 90);
    writeLine("And we're out of beta.", 0, 90);
    writeLine("We're releasing on time.", 300, 90);

    continueTune(); // 18
    drawPicture("explosion");
    writeLine("So I'm GLaD. I got burned.", 0, 90);

    continueTune(); // 19
    drawPicture("atom");
    writeLine("Think of all the things we learned", 0, 90);

    continueTune(); // 20
    drawPicture("aperture");
    writeLine("for the people who are", 0, 90);
    writeLine("still alive.", 1500, 90);

    clearArea();

    writeLine("FORMS Form-55551-6:", 0, 10);
    writeLine("Personnel File Addendum Addendum:", 400, 10);
    writeLine("", 100);
    writeLine("One last thing:", 200);
    writeLine("", 100);

    continueTune(); // 21
    writeLine("Go ahead and leave me.", 2100);

    continueTune(); // 22
    writeLine("I think I prefer to stay inside.", 2200);

    continueTune(); // 23
    writeLine("Maybe you'll find someone else", 1200);
    writeLine("to help you.", 2300);

    continueTune(); // 24
    drawPicture("blackmesa");
    writeLine("Maybe Black Mesa...", 2000, 120);
    writeLine("THAT WAS A JOKE. FAT CHANCE.", 2000, 130);

    continueTune(); // 25
    drawPicture("cake");
    writeLine("Anyway, this cake is great.", 1000);
    writeLine("It's so delicious and moist.", 100, 90);

    continueTune(); // 26
    drawPicture("glados");
    writeLine("Look at me still talking", 0, 90);

    continueTune(); // 27
    drawPicture("radioactive");
    writeLine("when there's Science to do.", 0, 90);

    continueTune(); // 28
    drawPicture("aperture");
    writeLine("When I look out there,", 0, 90);
    writeLine("it makes me GLaD I'm not you.", 200, 90);

    continueTune(); // 29
    drawPicture("atom");
    writeLine("I've experiments to run.", 0, 90);

    continueTune(); // 30
    drawPicture("explosion");
    writeLine("There is research to be done.", 0, 90);

    continueTune(); // 31
    drawPicture("aperture");
    writeLine("On the people who are", 0, 90);
    writeLine("still alive.", 1200, 90);
    clearArea();

    writeLine("", 100);
    writeLine("", 100);

    continueTune(); // 32
    writeLine("PS: And believe me I am", 0, 90);
    writeLine("still alive.", 600, 90);

    continueTune(); // 33
    writeLine("PPS: I'm doing Science and I'm", 0, 90);
    writeLine("still alive.", 600, 90);

    continueTune(); // 34
    writeLine("PPPS: I feel FANTASTIC and I'm", 0, 90);
    writeLine("still alive.", 100, 90);
    writeLine("", 100);

    continueTune(); // 35
    writeLine("FINAL THOUGHT:", 0, 90);
    writeLine("While you're dying I'll be", 0, 90);
    writeLine("still alive.", 0, 90);

    continueTune(); // 36
    writeLine("FINAL THOUGHT PS:", 0, 60);
    writeLine("And when you're dead I will be", 0, 80);
    writeLine("still alive.", 300);
    writeLine("", 100);
    writeLine("", 100);
    writeLine("STILL ALIVE", 5000, 120);

    clearArea();
    clearScreen();

    moveCursorTo(screenSizeX - 1, screenSizeY - 1);

    releaseScreen();
}

}