<?xml version="1.0"?>
<recipe>
    <merge from="AndroidManifest.xml.ftl" />

    <merge from="res/values/attrs.xml" />
    <merge from="res/values/colors.xml" />
    <merge from="res/values/styles.xml" />
    <merge from="res/values-v11/styles.xml" />
    <instantiate from="res/layout/activity_fullscreen.xml.ftl"
                   to="res/layout/${layoutName}.xml" />

    <merge from="res/values/strings.xml.ftl"
             to="res/values/strings.xml" />

    <instantiate from="src/app_package/FullscreenActivity.java.ftl"
                   to="${srcOut}/${activityClass}.java" />
    <instantiate from="src/app_package/util/SystemUiHider.java.ftl"
                   to="${srcOut}/util/SystemUiHider.java" />
    <instantiate from="src/app_package/util/SystemUiHiderBase.java.ftl"
                   to="${srcOut}/util/SystemUiHiderBase.java" />
    <instantiate from="src/app_package/util/SystemUiHiderHoneycomb.java.ftl"
                   to="${srcOut}/util/SystemUiHiderHoneycomb.java" />

    <open file="res/layout/${layoutName}.xml" />
</recipe>
