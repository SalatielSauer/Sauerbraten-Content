//mapthumb as background by Salatiel
//from line 192 to line 199
if (!mapname || mapshot==notexture){
    settexture("data/interface/background.png", 0);
} else {
    glBindTexture(GL_TEXTURE_2D, mapshot->id);
};
glBegin(GL_TRIANGLE_STRIP);
glColor4f(150, 150, 150, 150);
glTexCoord2f(0, 0); glVertex2f(0, 0);
glTexCoord2f(1, 0); glVertex2f(w, 0);
glTexCoord2f(0, 1); glVertex2f(0, h);
glTexCoord2f(1, 1); glVertex2f(w, h);
glEnd();
