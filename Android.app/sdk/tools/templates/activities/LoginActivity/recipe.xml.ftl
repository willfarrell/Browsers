<?xml version="1.0"?>
<recipe>
    <merge from="AndroidManifest.xml.ftl"
             to="${manifestOut}/AndroidManifest.xml" />

    <merge from="res/values/styles.xml"
             to="${resOut}/values/styles.xml" />
    <merge from="res/values-large/styles.xml"
             to="${resOut}/values-large/styles.xml" />
    <copy from="res/menu/activity_login.xml"
            to="${resOut}/menu/${menuName}.xml" />
    <instantiate from="res/layout/activity_login.xml.ftl"
                   to="${resOut}/layout/${layoutName}.xml" />

    <instantiate from="res/values/strings.xml.ftl"
                   to="${resOut}/values/strings_${simpleName}.xml" />

    <instantiate from="src/app_package/LoginActivity.java.ftl"
                   to="${srcOut}/${activityClass}.java" />

    <open file="${resOut}/layout/${layoutName}.xml" />
</recipe>
