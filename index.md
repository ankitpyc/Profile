---
# You don't need to edit this file, it's empty on purpose.
# Edit theme's home layout instead if you wanna make some changes
# See: https://jekyllrb.com/docs/themes/#overriding-theme-defaults
permalink : pretty
---

<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<title>index</title>
	<link rel="stylesheet" href="../css/profile.css">
</head>
<body>
	<div className="App">
<div className='sidebar-profile'>
<img className="background_profile_img" src="../static_assets/Profile_index/profile.jpg"/>
<div className="back_div">
<div className="nav">
 <ul className="nav_links"> 
  <li>Home</li>
  <li>About</li>
  <li>Resume</li>
  <li>Projects</li>
</ul>
</div>
<img className='profile_center' src={codename} />
<p className="para_intro">Hey There i am a Tech Enthusiast .love to work in react. 
Currenltly i am in my masters and working with machine Learning and Neural Networks !!</p>
</div>
</div>
<div className='sidebar-photo'>  
<div className='box'>
<div className='box-sidebar_img'>
<img src={MachineLearning} className="box_img"/>

</div>

<div className="sty">
<h5>Machine Learning</h5>
<p style={{fontSize : 12}}>I have been working  on ensembles and Neural Networks especially Natural Language Processing</p>
<button className="button_project">Projects</button>
</div>
</div>
<div className='box'>
<div className='box-sidebar_img'>
<img src={Webdevelopment}  className="box_img"/>
</div>
<div className="sty">
<h5>Web Development</h5>
<button className="button_project">Projects</button>
</div>
</div>
</div>
</div>
</body>
</html>
 