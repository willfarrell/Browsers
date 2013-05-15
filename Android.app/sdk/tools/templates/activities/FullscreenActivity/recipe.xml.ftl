<?xml version="1.0"?>
<recipe>
    <merge from="AndroidManifest.xml.ftl"
             to="${manifestOut}/AndroidManifest.xml" />

    <merge from="res/values/attrs.xml"
             to="${resOut}/values/attrs.xml" />
    <merge from="res/values/colors.xml"
             to="${resOut}/values/colors.xml" />
    <merge from="res/values/styles.xml"
              to="${resOut}/values/styles.xml" />
    <merge from="res/values-v11/styles.xml"
             to="${resOut}/values-v11/styles.xml" />
    <instantiate from="res/layout/activity_fullscreen.xml.ftl"
                   to="${resOut}/layout/${layoutName}.xml" />

    <merge from="res/values/strings.xml.ftl"
             to="${resOut}/values/strings.xml" />

    <instantiate from="src/app_package/FullscreenActivity.java.ftl"
                   to="${srcOut}/${activityClass}.java" />
    <instantiate from="src/app_package/util/SystemUiHider.java.ftl"
                   to="${srcOut}/util/SystemUiHider.java" />
    <instantiate from="src/app_package/util/SystemUiHiderBase.java.ftl"
                   to="${srcOut}/util/SystemUiHiderBase.java" />
    <instantiate from="src/app_package/util/SystemUiHiderHoneycomb.java.ftl"
                   to="${srcOut}/util/SystemUiHiderHoneycomb.java" />

    <open file="${resOut}/layout/${layoutName}.xml" />
</recipe>
