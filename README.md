# Browsers
A collection of aliases for browsers, services and virtual machine images can be found in the `Browsers` folder and added to your dock for easy launching.

![alt text][dockfolder]

Download and run `./alias` to build the `/Applications/Browsers/` forlder of shortcuts for quick access from your Dock. It searches `~/Virtual Machines/` for IE VMs (see `Internet Explorer (VM)` below for automated scripts to set these up). An alias of a VMWare Fusion VMs will display a broken preview icon instead of the expected app icon, to workaround this the alias is replaced with a script to launch the VM image. You may need to change you Terminal settings to prevent lingering Terminal windows from staying open.

---

**Launch Dev Tools (Mac):** ⌘ (command) + option + i

## [Android](http://developer.android.com) (VM)
Download from [developer.android.com](http://developer.android.com/sdk/index.html) or use the compiled app version [Android.app](Android.app) (Comes with Android 4.3). Made with [appify](https://gist.github.com/mathiasbynens/674099).

### Create and Run an Android Virtual Device (AVD)
1. Go to `Tools > Manage AVDs`
2. Click `New...`
3. Enter `AVD Name`, `Device`, `Target` and any other additional setting you need. Click `OK`.
4. Select AVD from list and click `Start...`


## [BlackBerry](http://developer.blackberry.com) (VM)
VMware Fusion is required, virtual machines can be found at [developer.blackberry.com](http://developer.blackberry.com/devzone/develop/simulator/simulator_installing.html).


## [Chrome](http://www.google.com/chrome) (Mac)
- [Chrome](http://www.chromium.org/getting-involved/dev-channel) Stable, Dev, Canary
- [Chrome Incognito](Google%20Chrome%20Incognito.app) - Direct opening of an Incognito window. [source](http://ente.limmat.ch/ftp/pub/software/applications/GoogleChromeIncognito/)
- [Chromium](http://www.macupdate.com/app/mac/36244/chromium) & the updater [Chromatic](http://www.macupdate.com/app/mac/32856/chromatic)
- [Chromium Benchmark](Google%20Chrome%20Incognito.app) - Open Chromium with --enable-benchmarking --enable-stats-table --enable-extension-timeline-api. Made with [appify](https://gist.github.com/mathiasbynens/674099).

## [Firefox](https://firefox.com) (Mac)
- [Firefox](https://firefox.com)
- [Firefox Beta](https://www.mozilla.org/en-US/firefox/channel/)
- [Firefox Aurora](https://www.mozilla.org/en-US/firefox/aurora/)
- [Firefox Nightly](https://nightly.mozilla.org/)
- [FirefoxDeveloperEdition](https://www.mozilla.org/en-US/firefox/developer/)
- [Firefox OS](https://developer.mozilla.org/en-US/docs/Tools/Firefox_OS_Simulator)
- [Firefox Boot2Gecko w/ Gaia](https://ftp.mozilla.org/pub/mozilla.org/b2g/nightly/latest-mozilla-central/)
 - [source](https://github.com/mozilla-b2g/gaia)
 - [Add-On Firefox OS Simulator](https://addons.mozilla.org/en-US/firefox/addon/firefox-os-simulator/)

## [Internet Explorer](http://www.modern.ie) (VM)
To run IE a virtual machine is required. IE6 - IE11 are available.

1. Virtual Box: [xdissent/ievms](https://github.com/xdissent/ievms) `curl -s https://raw.github.com/xdissent/ievms/master/ievms.sh | bash`
1. VMWare Fusion: [willfarrell/ievms](https://github.com/willfarrell/ievms) `curl -s https://raw.github.com/willfarrell/ievms/master/ievms.sh | bash`
1. Parallels: Visit [modern.ie](http://www.modern.ie/en-us/virtualization-tools#downloads) to download VMs.

## [iOS](http://developer.apple.com/library/ios/#documentation/IDEs/Conceptual/iOS_Simulator_Guide/Introduction/Introduction.html) (VM)
1. Install [Xcode](https://itunes.apple.com/ca/app/xcode/id497799835?mt=12).
1. Go to `Xcode > Preferences… > Downloads`.
1. Install Command Line Tools and iOS Simulator.

*/Applications/Xcode.app/Contents/Developer/Platforms/iPhoneSimulator.platform/Developer/Applications/iPhone Simulator.app*

## [Opera](http://www.opera.com/) (Mac)
- [Opera](http://www.opera.com/)
- [Opera Next](http://www.opera.com/developer/next)
- [Opera Developer](http://www.opera.com/developer)
- [Opera Mobile](http://www.opera.com/developer/mobile-emulator)
More tools can be found at [dev.opera.com](http://dev.opera.com/)

## [PhantomJS](http://phantomjs.org/) (Terminal)
Opens Terminal with phantomjs ready to go. Made with [appify](https://gist.github.com/mathiasbynens/674099)/[appify-UI](https://github.com/subtleGradient/Appify-UI). Requires phantomjs binaries to be installed. To install run `brew update && brew install phantomjs` or visit [phantomjs.org/download.html](http://phantomjs.org/download.html) if you don't use [`brew`](http://mxcl.github.io/homebrew/). There is an installer built-in if you like automation.

## [Safari](http://www.apple.com/safari/) (Mac)
- [Safari](http://www.apple.com/downloads/) - It's built into Mac OS X.
- [Webkit](http://nightly.webkit.org/)

# Other (less popular) Browsers
## [Arora](https://code.google.com/p/arora/) (Mac)

## [Camino](http://caminobrowser.org/download/) (Mac)
A slimed down version of Firefox.

## [OmniWeb](http://www.omnigroup.com/more) (Mac)
OmniWeb is a powerful, award-winning, feature-rich alternative to the standard web browser. Better organization and more fun with the original side-tabbed browser. (Requires OS X v10.4.8+)

## [SeaMonkey](http://www.seamonkey-project.org/) (Mac)

## [Stainless](http://www.stainlessapp.com/) (Mac)

## [TorBrowser](https://www.torproject.org/download/download) (Mac)
For testing site using Tor.

# Virtual Machines
- [Oracle VM VirtualBox](https://www.virtualbox.org/)
- [VMware Fusion](http://www.vmware.com/products/fusion/overview.html)
- [Vagrant](http://www.vagrantup.com/)
- [Docker](http://docker.io) - The Linux Container Engine.

# Third Party Services
- [BrowserStack](http://www.browserstack.com/start) - A Fluid app of browserstack.com dashboard. [Download](BrowserStack.app)
- [Sause Labs](https://saucelabs.com/) - Can be downloaded from the [Mac Store](https://itunes.apple.com/ca/app/sauce/id564308477?mt=12). 


# Continuous Integration (CI)
- [karma](http://karma-runner.github.io/0.8/index.html) - The main goal for Karma is to bring a productive testing environment to developers. An environment, where they don't have to set up many things and rather just write the code and get an instant feedback. Because getting a quick feedback is what makes you productive and creative. Requires [nodejs](http://nodejs.org/download/), and works great with [grunt](http://gruntjs.com/getting-started).
- [Travis CI](https://travis-ci.org/) - A hosted continuous integration service for the open source community.
- [Jenkins](http://jenkins-ci.org/) - An extendable open source continuous integration server.
- [Mac mini CI](https://github.com/angular/ci.angularjs.org) - Shell scripts and configuration files used by the Google AngularJS Team. [Video](https://www.youtube.com/watch?v=BNpV7npURhE) [Slides](https://docs.google.com/presentation/d/1-j264F0Q8k3NzionQspx7fhKd2E8XPkIKItxz2qhN28)

[dockfolder]: ./dock-folder.png "Browser Alias Folder"

# Boxen Packages
- [All Browsers](https://github.com/boxen/puppet-browsers)

- [Android](https://github.com/boxen/puppet-android)
- BlackBerry :: None yet.
- [Chrome](https://github.com/boxen/puppet-chrome)
- [Firefox](https://github.com/boxen/puppet-firefox)
- Internet Explorer :: None yet.
- iOS :: Included in Mac Xcode
- [Opera](https://github.com/boxen/puppet-opera)
- [PhantomJS](https://github.com/boxen/puppet-phantomjs)
- Safari :: Already include on Mac
- TorBrowser - Not build yet.

- [Virtual Box](https://github.com/boxen/puppet-virtualbox)
- [Vagrant](https://github.com/boxen/puppet-vagrant)
- VMWare Fusion :: Not built yet.

- BrowserStack :: Not built yet.
- Sause Labs :: Not built yet.

- [Jenkins](https://github.com/boxen/puppet-jenkins)

# Browser Extensions
## Privacy & Security
Google **C**hrome, Mozilla **F**irefox, Microsoft **I**nternet Explorer, **O**pera, Apple **S**afari

- **CF-O-** [Adblock Plus](http://adblockplus.org/en/) - The free adblock tool for Chrome: Blocks annoying video ads on YouTube, Facebook ads, banners and much more.
- **CF--S** [1Password](https://agilebits.com/extensions/mac/index.html) - 1Password for Mac extension.
- **CF-OS** [Disconnect](https://disconnect.me/) - Protect your privacy.
- **CFIOS** [Ghostery](http://www.ghostery.com/) - Protect your privacy. See who's tracking your web browsing with Ghostery.
- **CFIOS** [Google Analytics Opt-out Browser Add-on](https://tools.google.com/dlpage/gaoptout) - Tells the Google Analytics JavaScript not to send information to Google Analytics.
- **CF---** [HTTPS Everywhere](https://www.eff.org/https-everywhere) - Encrypt the Web! Automatically use HTTPS security on many sites.
- **CF---** [Mailvelope](http://www.mailvelope.com/) - Secure email with OpenPGP encryption for Webmail
- **CFIOS** [Terms of Service; Didn’t Read](http://tosdr.org/) - Get information instantly about websites' terms of service and privacy policies, with ratings and summaries from the www.tosdr.org.

### [Chrome Dev Extensions](https://chrome.google.com/webstore/category/ext/11-web-development)
- [Adobe Edge Inspect CC](https://chrome.google.com/webstore/detail/adobe-edge-inspect/ijoeapleklopieoejahbpdnhkjjgddem) - Wirelessly connect multiple iOS & Android devices to your computer. Synchronously browse, inspect & debug on devices.
- [AngularJS Batarang](https://chrome.google.com/webstore/detail/angularjs-batarang/ighdmehidhipcmcojjgiloacoafjmpfk) - Extends the Developer Tools, adding tools for debugging and profiling AngularJS applications.
- [blitz](https://chrome.google.com/webstore/detail/blitz/dfdmpnkoalkolclnaipnopkooilhnped) - Instantly load test your app from around the world with just a few clicks. No scripting and no test creation.
- [Chrome Logger](https://chrome.google.com/webstore/detail/chrome-logger/noaneddfkdjfnfdakjjmocngnfkfehhd) - For server side logging and debugging in chrome console.
- [Chrome Sniffer](https://chrome.google.com/webstore/detail/chrome-sniffer/homgcnaoacgigpkkljjjekpignblkeae) - Detect web applications and javascript libraries run on browsing website.
- [Clear Cache](https://chrome.google.com/webstore/detail/clear-cache/cppjkneekbjaeellbfkmgnhonkkjfpdn)
- [Edit This Cookie](https://chrome.google.com/webstore/detail/edit-this-cookie/fngmhnnpilhplaeedifhccceomclgfbg) - Edit This Cookie is a cookie manager. You can add, delete, edit, search, protect and block cookies!
- [Extensions Reloader](https://chrome.google.com/webstore/detail/extensions-reloader/fimgfedafeadlieiabdeeaodndnlbhid) - Reload all unpacked extensions using the extension's toolbar button or by browsing to "http://reload.extensions"
- [FirePHP4Chrome](https://chrome.google.com/webstore/detail/firephp4chrome/gpgbmonepdpnacijbbdijfbecmgoojma) - Show FirePHP log messages in the Chrome Developer Console
- [github+travis](https://chrome.google.com/webstore/detail/github%20travis/klbmicjanlggbmanmpneloekhajhhbfb) - Display build status next to the project name on github.
- [Google Analytics Opt-out](https://chrome.google.com/webstore/detail/google-analytics-opt-out/fllaojicojecljbmefodhfapmkghcbnh) - Tells the Google Analytics JavaScript not to send information to Google Analytics.
- [Grunt Devtools](https://chrome.google.com/webstore/detail/grunt-devtools/fbiodiodggnlakggeeckkjccjhhjndnb?hl=en) - Extends the Developer Tools, adding tools for Grunt
- [Jenkins Notifier for Chrome](https://chrome.google.com/webstore/detail/jenkins-notifier-for-chro/mnjbjjllbclkpnebaddhkoonjelmiekm) - Jenkins Notifier for Chrome™ is an (unofficial) extension for Jenkins ( http://jenkins-ci.org ). This extension notifies you of…
- [JSONView](https://chrome.google.com/webstore/detail/jsonview/chklaanhfefbnpoihckbnefhakgolnmc) - Validate and view JSON documents
- [LiveReload](https://chrome.google.com/webstore/detail/livereload/jnihajbhpnppcggbcgedagnkighmdlei) - Provides Chrome browser integration for the official LiveReload apps (Mac & Windows) and third-parties like guard-livereload and…
- [My Travis](https://chrome.google.com/webstore/detail/my-travis/ddlafmkcenhiahiikbgjemcbdengmjbg) - Monitor your projects builds from Travis CI within Chrome.
- [Octotree](https://chrome.google.com/webstore/detail/octotree/bkhaagjahfmjljalopjnoealnfndnagc) - Folder view of github repo tree.
- [Page Benchmarker](https://chrome.google.com/webstore/detail/page-benchmarker/channimfdomahekjcahlbpccbgaopjll/details?hl=en) - Chromium Page Benchmarker.
- [PageSpeed Insights (by Google)](https://chrome.google.com/webstore/detail/pagespeed-insights-by-goo/gplegfbjlmmehdoakndmohflojccocli) - PageSpeed Insights analyzes the performance of your web pages and provides suggestions to make them faster.
- [Pendule](https://chrome.google.com/webstore/detail/pendule/gbkffbkamcejhkcaocmkdeiiccpmjfdi) - Web developer tools for Chrome.
- [Pretty Beautify Javascript](https://chrome.google.com/webstore/detail/pretty-beautiful-javascri/piekbefgpgdecckjcpffhnacjflfoddg) - Automatically makes Javascript files pretty and beautiful!
- [Postman - REST Client](https://chrome.google.com/webstore/detail/postman-rest-client/fdmmgilgnpjigdojojpjoooidkmcomcm?hl=en)
- [Responsive Inspector](https://chrome.google.com/webstore/detail/responsive-inspector-beta/memcdolmmnmnleeiodllgpibdjlkbpim) - Responsive Inspector allows inspecting page media queries.
- [Ripple Emulator](https://chrome.google.com/webstore/detail/ripple-emulator-beta/geelfhphabnejjhdalkjhgipohgpdnoc) - A browser based html5 mobile application development and testing tool
- [Speed Tracer](https://chrome.google.com/webstore/detail/speed-tracer-by-google/ognampngfcbddbfemdapefohjiobgbdl) - Get insight into the performance of your web applications.
- [YSlow](https://chrome.google.com/webstore/detail/yslow/ninejjcohidippngpapiilnmkgllmakh) - Make your pages faster with Yahoo!'s page performance tool

### [Firefox Dev Add-Ons](https://addons.mozilla.org/en-US/firefox/)
- [Firefox OS Simulator](https://people.mozilla.com/~myk/r2d2b2g/)
- [LiveReload](http://feedback.livereload.com/knowledgebase/articles/86242-how-do-i-install-and-use-the-browser-extensions-)

### [Safari Dev Extensions](http://extensions.apple.com/)
- [LiveReload](http://feedback.livereload.com/knowledgebase/articles/86242-how-do-i-install-and-use-the-browser-extensions-)