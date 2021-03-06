/* (c)  oblong industries */


#include "Greenhouse.h"
#include "DummyObject.h"

/**
  When using new resource files please be sure to do the following in order to
  ensure that your application can find those resources:

    - Place all resource files in:

        /opt/oblong/greenhouse/share

    - OR if you'd like to keep your resource files separated from the installed
         resources:

      Create a folder for your personal resource files and add the following
      line to your ~/.bash_profile (Mac) or ~/.bashrc (Linux) file:

        export OB_SHARE_PATH=[/path/to/new/share]:$OB_SHARE_PATH
**/



void Setup ()
{ 
    DummyObject *repeller = new DummyObject(true);
    DummyObject* dobj = new DummyObject(false);
    repeller->SetScale(1.0f);
    dobj->SetScale(2.0f);
};
