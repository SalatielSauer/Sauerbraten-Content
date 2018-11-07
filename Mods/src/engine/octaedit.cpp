//Barbecue, allow edit in view, line 149
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
	//if(!viewable && msg) conoutf(CON_ERROR, "selection not in view");
	//return !viewable;
    if(!viewable && editinview && msg) {conoutf(CON_ERROR, "selection not in view");}
	if (editinview){
    		return !viewable;
	}
	else
	{
		return false;	
	}
}

//Barbecue, pushface
//arg1: -1 || 1 (add or subtract arg2)
//arg2: 0 = X || 1 = Y || 2 = Z
void pushface(int *dir, int *pface)
{
    if(noedit(moving!=0)) return;
    int s = *dir;
    sel.o[*pface] += s*sel.grid;
}
COMMAND(pushface, "ii"); //
