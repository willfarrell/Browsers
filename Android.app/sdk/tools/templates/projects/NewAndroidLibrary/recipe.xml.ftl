<?xml version="1.0"?>
<recipe>
<#if isGradle == "true">
    <merge from="settings.gradle.ftl"
             to="${topOut}/settings.gradle" />
    <instantiate from="build.gradle.ftl"
                   to="${projectOut}/build.gradle" />
</#if>
    <instantiate from="MODULE_NAME/src/main/AndroidManifest.xml.ftl"
                   to="${manifestOut}/AndroidManifest.xml" />

<#if copyIcons>
    <copy from="res/drawable-hdpi"
            to="${resOut}/drawable-hdpi" />
    <copy from="res/drawable-mdpi"
            to="${resOut}/drawable-mdpi" />
    <copy from="res/drawable-xhdpi"
            to="${resOut}/drawable-xhdpi" />
</#if>
    <instantiate from="res/values/styles.xml.ftl"
                   to="${resOut}/values/styles.xml" />
<#if buildApi gte 11 && baseTheme != "none">
    <instantiate from="res/values-v11/styles_hc.xml.ftl"
                   to="${resOut}/values-v11/styles.xml" />
</#if>
<#if buildApi gte 14 && baseTheme?contains("darkactionbar")>
    <copy from="res/values-v14/styles_ics.xml"
            to="${resOut}/values-v14/styles.xml" />
</#if>

    <instantiate from="res/values/strings.xml.ftl"
                   to="${resOut}/values/strings.xml" />
</recipe>
