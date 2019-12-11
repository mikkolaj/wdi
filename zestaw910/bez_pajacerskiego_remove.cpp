void remove(node *&f, int val){
	if(f == NULL)	return;
	node *r = f;				//r = robocza
	node *p = NULL;				//p = prev
	while(r != NULL && r->w != val){
		p = r;
		r = r->next;
	}
	if(r == NULL)	return;		//jeśli wyszło z while bo r == NULL
	if(p != NULL) {				//wiemy że r->w to val
		p->next = r->next;
	}
	else {						//to pierwszy element
		f = f->next;
	}
	delete p;
}
