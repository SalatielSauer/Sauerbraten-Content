//Barbecue, allow edit in view
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
	
	//Barbecue, allow edit in view
	//if(!viewable && msg) {conoutf(CON_ERROR, "selection out of view");}
	//return !viewable;
    if(!viewable && editinview && msg) {conoutf(CON_ERROR, "selection out of view");}
	if (editinview){
    		return !viewable;
	}
	else
	{
		return false;	
	}
}
