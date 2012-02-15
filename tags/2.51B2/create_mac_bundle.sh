#!/bin/bash
APPNAME=${1}
TMPFILE=/tmp/plist.tmp
CONTENTS=$APPNAME.app/Contents

MINORVER=`sed -n 's/^#define[ \t]*VERSION_MINOR[^0-9]*\([^"]*\).*/\1/p' version_info.h`
BETAEXT=`sed -n 's/^#define[ \t]*BETA_EXT[^0-9B]*\([^"]*\).*/\1/p' version_info.h`
DATESTR=`date +%Y%m%d`
cd release
mkdir -p $CONTENTS/Resources/language
mkdir -p $CONTENTS/PlugIns/modules
mkdir -p $CONTENTS/Frameworks
cp ../*.qm $CONTENTS/Resources/language/
cp ../modules/*.mod $CONTENTS/PlugIns/modules/
cp ../resources/$APPNAME.icns $CONTENTS/Resources/$APPNAME.icns
cp -R ../mac/* $CONTENTS/MacOS
# POS=`pwd`
# cd $CONTENTS/MacOS
# ln -s ../Frameworks/VLCKit.framework/lib .
# cd $POS
sed -e "s/$APPNAME.rc/$APPNAME.icns/g" -e "s/yourcompany/Jo2003/g" $CONTENTS/Info.plist >$TMPFILE
iconv -f ASCII -t UTF-8 $TMPFILE >$CONTENTS/Info.plist
macdeployqt $APPNAME.app -dmg -verbose=0
mv $APPNAME.dmg $APPNAME-2.${MINORVER}${BETAEXT}-${DATESTR}-mac.dmg
cd ..

