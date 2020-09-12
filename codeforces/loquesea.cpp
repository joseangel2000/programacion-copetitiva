cin>>n>>m;
	for (int i=0;i<n;i++)
	{
		cin>>l>>r;
		if (i) s.insert({{r-L,l-R},i});
		L=l,R=r;
	}
	for (int i=0;i<m;i++)
		cin>>x,k.insert({x,i});
	for (auto se : s)
	{
		auto i = k.lower_bound({se.first.second,-1});
		if (i==k.end() || i->first > se.first.first )
		{
			cout<<"No";
			return 0;
		}
		ans[se.second]=i->second;
		k.erase(i);
	}
	cout<<"Yes \n";
	for (int i=1;i<n;i++) cout<<ans[i]+1<<" ";
	return 0;
