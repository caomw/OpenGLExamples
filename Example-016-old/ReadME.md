<A href="http://www.opengl.org"><IMG src='https://www.khronos.org/assets/images/api_logos/opengl.png' border=0 width="180" 
height="97"></A>

<H3>The <i>'Example-016 (Old Mode)'</i> Test</H3>

The <i>'Example-016 (Old Mode)'</i> Test draws 2 triangle fans, approximating the <i>'Square Annulus'</i> shape, in an <A href="http://www.opengl.org"><i>OpenGL</i></A> window. The reference vertices of the triangle fans are depicted, respectively, in <i>'red'</i> (indicated as the <i>'Triangle Fan #0'</i>) and in <i>'blue'</i> (indicated as the <i>'Triangle Fan #1'</i>), while their triangles are depicted in <i>'turquoise gray'</i>. The settings for rendering the triangles in the triangle fans of interest can be modified interactively by the user as follows:<p><ul>
<li>only the <i>'front'</i> sides of the triangles in the triangle fans of interest are rendered by pressing the <i>'f'</i> or the <i>'F'</i> key. The corresponding rendering type is chosen by the user separately.<p></li>
<li>Only the <i>'back'</i> sides of the triangles in the triangle fans of interest are rendered by pressing the <i>'b'</i> or the <i>'B'</i> key. The corresponding rendering type is chosen by the user separately.<p></li>
<li>Both the <i>'front'</i> and the <i>'back'</i> sides of the triangles in the triangle fans of interest are rendered by pressing the <i>'t'</i> or the <i>'T'</i> key. The corresponding rendering type is chosen by the user separately.<p></li>
<li>Only the vertices for the sides of the triangles in the triangle fans to be drawn are rendered by pressing the <i>'p'</i> or the <i>'P'</i> key. The user can choose separately what sides of the triangles must be drawn.<p></li>
<li>The <i>'wireframe versions'</i> for the sides of the triangles in the triangle fans to be drawn are rendered by pressing the <i>'l'</i> or the <i>'L'</i> key. The user can choose separately what sides of the triangles must be drawn.<p></li>
<li>The <i>'filled versions'</i> for the sides of the triangles in the triangle fans to be drawn are rendered by pressing the <i>'i'</i> or the <i>'I'</i> key. The user can choose separately what sides of the triangles must be drawn.<p></li></ul><p>Likewise, the window of interest can be closed by pressing any among the <i>'Q'</i>, the <i>'q'</i>, and the <i>'Esc'</i> keys.<p><h5>Rendering only the <i>'front'</i> sides of the triangles</h5><p><table border=0 width=100%><tr>
<td width=50%><IMG style=float:middle src='http://davidcanino.github.io/img/shots_opengl/shot_example016_old_fan0_points.png' border='1' width='456' height='470'></td>
<td width=50%><IMG style=float:middle src='http://davidcanino.github.io/img/shots_opengl/shot_example016_old_fan0_wireframe.png' border='1' width='456' height='470'></td></tr>
<tr><td><i>'Points rendering'</i> (press the <i>'p'</i> or the <i>'P'</i> key).</td><td>The <i>'wireframe version'</i> (press the <i>'l'</i> or the <i>'L'</i> key).</td></tr>
<tr>
<td width=50%><IMG style=float:middle src='http://davidcanino.github.io/img/shots_opengl/shot_example016_old_fan0_filled.png' border='1' width='456' height='470'></td>
<td>In this case, the <i>'front'</i> sides of the triangles in the <i>'Triangle Fan #1'</i> are not rendered, due to their vertices order. In the code, these latters are enumerated in the clockwise order, thus every triangle is a back-faced triangle. Hence, the <i>'Triangle Fan #1'</i> remains unchanged, when the user decides to render only the <i>'front'</i> sides of all triangles.<p>

Instead, the <i>'Triangle Fan #0'</i> is formed only by front-faced triangles, thus the <i>'front sides'</i> of its triangles can be rendered.<p>This is true, even if changing the rendering type for the triangles (points, wireframe, filled).</td></tr>
<tr><td width=50%>The <i>'filled version'</i> (press the <i>'i'</i> or the <i>'I'</i> key).</td><td><b>IMPORTANT</b></td></tr></table><p><h5>Rendering only the <i>'back'</i> sides of the triangles</h5><p>
<table border=0 width=100%><tr>
<td width=50%><IMG style=float:middle src='http://davidcanino.github.io/img/shots_opengl/shot_example016_old_fan1_points.png' border='1' width='456' height='470'></td>
<td width=50%><IMG style=float:middle src='http://davidcanino.github.io/img/shots_opengl/shot_example016_old_fan1_wireframe.png' border='1' width='456' height='470'></td></tr>
<tr><td><i>'Points rendering'</i> (press the <i>'p'</i> or the <i>'P'</i> key).</td><td>The <i>'wireframe version'</i> (press the <i>'l'</i> or the <i>'L'</i> key).</td></tr>
<tr>
<td width=50%><IMG style=float:middle src='http://davidcanino.github.io/img/shots_opengl/shot_example016_old_fan1_filled.png' border='1' width='456' height='470'></td>
<td>In this case, the <i>'back'</i> sides of the triangles in the <i>'Triangle Fan #0'</i> are not rendered, due to their vertices order. In the code, these latters are enumerated in the counter-clockwise order, thus every triangle is a front-faced triangle. Hence, the <i>'Triangle Fan #0'</i> remains unchanged, when the user decides to render only the <i>'back'</i> sides of all triangles.<p>

Instead, the <i>'Triangle Fan #1'</i> is formed only by back-faced triangles, thus the <i>'back sides'</i> of its triangles can be rendered.<p>This is true, even if changing the rendering type for the triangles (points, wireframe, filled).</td></tr>
<tr><td width=50%>The <i>'filled version'</i> (press the <i>'i'</i> or the <i>'I'</i> key).</td><td><b>IMPORTANT</b></td></tr></table><p><h5>Rendering both the <i>'front'</i> and the <i>'back'</i> sides of the triangles</h5><p>
<table border=0 width=100%><tr>
<td width=50%><IMG style=float:middle src='http://davidcanino.github.io/img/shots_opengl/shot_example016_old_points.png' border='1' width='456' height='470'></td>
<td width=50%><IMG style=float:middle src='http://davidcanino.github.io/img/shots_opengl/shot_example016_old_wireframe.png' border='1' width='456' height='470'></td></tr>
<tr><td><i>'Points rendering'</i> (press the <i>'p'</i> or the <i>'P'</i> key).</td><td>The <i>'wireframe version'</i> (press the <i>'l'</i> or the <i>'L'</i> key).</td></tr>
<tr>
<td width=50%><IMG style=float:middle src='http://davidcanino.github.io/img/shots_opengl/shot_example016_old_filled.png' border='1' width='456' height='470'></td>
<td>As consequence, it is clear that the triangle fans can be rendered separately, except when both the <i>'front'</i> and the <i>'back'</i> sides of all triangles are rendered at the same time.<p>

In this case, both the <i>'Triangle Fan #0'</i> and the <i>'Triangle Fan #1'</i> (more specifically, their <i>'front'</i> and <i>'back'</i> sides) satisfy completely the rendering settings, chosen by the user.</td></tr>
<tr><td width=50%>The <i>'filled version'</i> (press the <i>'i'</i> or the <i>'I'</i> key).</td><td><b>IMPORTANT</b></td></tr></table><hr><p>

<h4>Dependencies</h4>

The <i>'Example-016 (Old Mode)'</i> Test is based on the so-called <i>OpenGL old (direct drawing) mode</i>, and requires the following dependencies:<ul>

<li>the <A href="http://www.opengl.org"><i>OpenGL</i></A> package, distributed with the platform of interest (see the <i><A href="https://www.khronos.org/opengl/wiki/Getting_Started">Official Documentation</A></i>);</li>
<li>the <i><A href="https://www.opengl.org/resources/libraries/glut/">OpenGL Utility Toolkit (GLUT)</A></i> package (or the <A href="http://freeglut.sourceforge.net/"><i>FreeGLUT</i></A> package);</li>
<li>the <A href="http://glew.sourceforge.net/"><i>OpenGL Extension Wrangler Library (GLEW)</i></A> package.</li></ul><p>In particular, this test consists of the <i>'Example-016-old'</i> executable file (in the <i>'bin'</i> folder), starting uniquely from the <i>'main.cpp'</i> C++ source file (in the <i>'src'</i> folder).<p>Several methods for building this test are provided.<p><table border=1><tr><td><p><b>ATTENTION:</b><p>The majority of the dependencies for this test are stable, but are currently deprecated, and several warning messages may appear during the building process.<p></td></tr></table><p><hr><p>

<h4>Instructions for building this test with the <i><A href="http://cmake.org">CMake Building Tool</A></i></h4>

This test is built by using the <i>classic</i> instructions for building a program with the <i><A href="http://cmake.org">CMake Building Tool</A></i> from the <i>'cmake'</i> folder:
<pre>mkdir build
cd build
cmake ..
make
</pre><p>As mentioned above, the <i>'Example-016-old'</i> executable file is created in the <i>'bin'</i> folder. For instance, this test is executed by running:<pre>./bin/Example-016-old</pre><p>This building method is tested with the <A href="http://gcc.gnu.org/"><i>GCC</i></A> under the Ubuntu Linux 16.0.4 (LTS), as well as with the <A href="http://clang.llvm.org/"><i>CLANG</i></A> compiler under the MacOsX 11.* El-Capitan (and higher), and the <A href="http://www.visualstudio.com/"><i>Microsoft Visual Studio (Community Edition 2015)</i></A> under the Microsoft Windows 10.<p>In this latter case, three custom projects are automatically generated, and ready to be open in the <A href="http://www.visualstudio.com/"><i>Microsoft Visual Studio (Community Edition 2015)</i></A>. The solution file of interest is the <i>'Example-016-old.sln'</i> solution file, which can be open and built in the program without being modified.<p>

All dependencies of the <i>'Example-016 (Old Mode)'</i> Test are supported automatically by the <i><A href="http://cmake.org">CMake Building Tool</A></i> through a built-in manifest file. In particular, they are often pre-installed in a generic GNU/Linux distribution, and distributed in conjunction with the <A href="http://developer.apple.com/xcode/"><i>Apple XCode</i></A>. Thus, they should be found by the script of interest without problems in these platforms.<p>Instead, these libraries are not standard in the Microsoft Windows, and must be installed properly. For the sake of simplicity, the Win32 versions for the auxiliary libraries of interest in the <i>'../../depends'</i> folder are exploited, if the <i><A href="http://cmake.org">CMake Building Tool</A></i> fails while performing their automatic identification. This means that the resulting solution file creates automatically the <i>'Example-016-old.exe'</i> Win32 executable file.<p><hr><p>

<h4>Instructions for building this test with the <i><A href="http://www.visualstudio.com/">Microsoft Visual Studio (Community Edition 2015)</A></i></h4>

This test is also built by using the <A href="http://www.visualstudio.com/"><i>Microsoft Visual Studio (Community Edition 2015)</i></A>. In particular, the <i>'vstudio'</i> folder contains the <i>'Example-016-old.sln'</i> solution file, which can be open and built in the program without being modified. It can be built by simply clicking on the <i>'Build'</i> command.

Note that this solution file is independently created from scratch, and is different from the solution file, which may be generated automatically by the <i><A href="http://cmake.org">CMake Building Tool</A></i>.

Specifically, the Win32 versions for the auxiliary libraries of interest in the <i>'../../depends'</i> folder are exploited for building the  <i>'Example-016 (Old Mode)'</i> Test. This implies that the <i>'Example-016-old.sln'</i> solution file is set up for including these auxiliary libraries, and it should not be modified, unless you are an expert. Furthermore, it is mandatory to enable the building for a generic Win32 platform for creating correctly the <i>'Example-016-old.exe'</i> Win32 executable file.<p>An interested user finds more details in the Official Documentation of the <i><A href="http://www.visualstudio.com/">Microsoft Visual Studio (Community Edition 2015)</A></i>.<p><hr><p>

<h4>Instructions for building this test with the <i><A href="http://developer.apple.com/xcode/">Apple XCode</A></i></h4>

This test is also built by using the <A href="http://developer.apple.com/xcode/"><i>Apple XCode</i></A> (based on the <A href="http://clang.llvm.org/"><i>CLANG</i> compiler</A>) under the MacOsX 11.* El-Capitan (and higher). In particular, the <i>'xcode'</i> folder contains the <i>'Example-016-old.xcodeproj'</i> project file, which can be open and built in the program without being modified. It can be built by simply clicking on the <i>'Build & Run'</i> command.

Note that this project file is independently created from scratch, and is different from the project file, which may be generated automatically by the <i><A href="http://cmake.org">CMake Building Tool</A></i>.<p>

Specifically, this project file includes the versions (frameworks) of the <A href="http://www.opengl.org"><i>OpenGL</i></A> and of the <i><A href="https://www.opengl.org/resources/libraries/glut/">OpenGL Utility Toolkit (GLUT)</A></i> packages, that are distributed in conjunction with the <A href="http://developer.apple.com/xcode/"><i>Apple XCode</i></A>. Instead, the headers and the library files of the <A href="http://glew.sourceforge.net/"><i>OpenGL Extension Wrangler Library (GLEW)</i></A> are assumed to be stored in the <i>'/usr/local/include'</i> and the <i>'/usr/local/lib'</i> folders, respectively. This implies that the <i>'Example-016-old.xcodeproj'</i> project file is set up for including these auxiliary libraries, and it should not be modified, unless you are an expert.<p>An interested user finds more details in the Official Documentation of the <A href="http://developer.apple.com/xcode/"><i>Apple XCode</i></A>.<p><hr><p><table border=1><tr><td><p><b>ATTENTION:</b><p>This test is not related officially to the <i><A href="https://www.khronos.org/">Khronos Group</A></i>. All trademarks or registered trademarks are the property of their respective owners.</td></tr></table>
