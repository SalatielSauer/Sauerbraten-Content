//S: Allow Edit out of view
VARP(editinview, 0, 1, 1);

bool noedit(bool view, bool msg)
{
    if(!editmode) { if(msg) conoutf(CON_ERROR, "operation only allowed in edit mode"); return true; }
    if(view || haveselent()) return false;
    float r = 1.0f;
    vec o = sel.o.tovec(), s = sel.s.tovec();
    s.mul(float(sel.grid) / 2.0f);
    o.add(s);
    r = float(max(s.x, max(s.y, s.z)));
    bool viewable = (isvisiblesphere(r, o) != VFC_NOT_VISIBLE);

    //S: Allow Edit out of view
    /*if(!viewable && msg) conoutf(CON_ERROR, "selection not in view");
    return !viewable;*/
    if(!viewable && editinview && msg) {conoutf(CON_ERROR, "selection not in view");}
    if (editinview){return !viewable;} else {return false;}
}

//Selection commands expansion, by Salatiel.

//S: Get selection position, based on getcampos
ICOMMAND(getselpos, "", (),
{
    defformatstring(pos)("%s %s %s", floatstr(sel.o.x), floatstr(sel.o.y), floatstr(sel.o.z));
    result(pos);
});

/*
S: Move selection to given position
/setselpos x y z
*/
void setselpos(int *posx, int *posy, int *posz)
{
     sel.o.x = *posx - *posx % 16;
     sel.o.y = *posy - *posy % 16;
     sel.o.z = *posz - *posz % 16;
}
COMMAND(setselpos, "iii");

/*
S: Move selection to given direction (arg1: add/subtract | arg2: x y z)
*/
void movesel(int *dir, int *pface)
{
    if(noedit(moving!=0)) return;

    if((*pface > 2) || (*pface < 0))
    {
        conoutf(CON_ERROR, "valid range for movesel is 0..2");
        return;
    };
    int s = *dir;
    sel.o[*pface] += s*sel.grid;
}
COMMAND(movesel, "ii");
